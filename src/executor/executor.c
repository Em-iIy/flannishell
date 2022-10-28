/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/22 16:29:32 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/10/27 19:21:01 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor_utils.h"
#include "executor.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static int	do_fork(t_cmd *command, t_pipe *pipes, char **env)
{
	pipes->i++;
	pipes->pid[pipes->i] = fork();
	if (pipes->pid[pipes->i] < 0)
		return (2);
	if (pipes->pid[pipes->i] == 0)
		exec_command(command, pipes, env);
	return (0);
}

static int	wait_forks(t_pipe *pipes)
{
	int	i;
	int	status;

	i = 0;
	while (i <= pipes->i)
	{
		if (waitpid(pipes->pid[i], &status, 0) == -1)
			return (2);
		i++;
	}
	free(pipes->pid);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}

int	executor(t_parser *parser, char **env)
{
	t_cmd		*command;
	t_pipe		pipes;

	pipes.pid = (int *)malloc((parser->count) * sizeof(int));
	if (!pipes.pid)
		return (ENOMEM);
	command = parser->cmds;
	pipes.in_fd = STDIN_FILENO;
	pipes.i = -1;
	while (command)
	{
		if (command->next)
			if (pipe(pipes.tube))
				return (2);
		if (do_fork(command, &pipes, env))
			return (2);
		if (!command->lst_cmd && close(pipes.tube[1]))
			return (2);
		if (!command->frst_cmd && close(pipes.in_fd))
			return (2);
		pipes.in_fd = pipes.tube[0];
		command = command->next;
	}
	return (wait_forks(&pipes));
}
