/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/22 16:29:32 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/10/26 16:56:11 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor_utils.h"
#include "executor.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static int	do_fork(t_cmd *command, t_pipe *pipes, int *pid, char **env)
{
	pipes->pid_i++;
	pid[pipes->pid_i] = fork();
	if (pid[pipes->pid_i] < 0)
		return (1);
	if (pid[pipes->pid_i] == 0)
		exec_command(command, pipes, env);
	return (0);
}

static int	wait_forks(t_pipe *pipes, int *pid)
{
	int	i;
	int	status;

	i = 0;
	while (i <= pipes->pid_i)
	{
		if (waitpid(pid[i], &status, 0) == -1)
			return (2);
		i++;
	}
	free(pid);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}

int	executor(t_parser *parser, char **env)
{
	t_cmd		*command;
	t_pipe		pipes;
	int			*pid;

	pid = (int *)malloc((parser->count - 1) * sizeof(int));
	if (!pid)
		return (ENOMEM);
	command = parser->cmds;
	pipes.in_fd = STDIN_FILENO;
	pipes.pid_i = -1;
	while (command)
	{
		if (command->next)
			if (pipe(pipes.tube))
				return (1);
		if (do_fork(command, &pipes, pid, env))
			return (1);
		if (!command->lst_cmd && close(pipes.tube[1]))
			return (1);
		if (!command->frst_cmd && close(pipes.in_fd))
			return (1);
		pipes.in_fd = pipes.tube[0];
		command = command->next;
	}
	return (wait_forks(&pipes, pid));
}
