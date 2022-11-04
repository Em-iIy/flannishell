/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:29:32 by fpurdom           #+#    #+#             */
/*   Updated: 2022/11/04 12:02:27 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "executor_utils.h"
#include "executor.h"
#include "builtins.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static int	do_fork(t_cmd *command, t_pipe *pipes, t_env *env)
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
	free(pipes);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}

static t_pipe	*init_pipe(int size)
{
	t_pipe	*pipes;

	pipes = (t_pipe *)malloc(1 * sizeof(t_pipe));
	if (!pipes)
		exit (ENOMEM);
	pipes->pid = (int *)malloc((size) * sizeof(int));
	if (!pipes->pid)
		exit (ENOMEM);
	pipes->in_fd = STDIN_FILENO;
	pipes->i = -1;
	return (pipes);
}

int	executor(t_parser *parser, t_env *env)
{
	t_cmd		*command;
	t_pipe		*pipes;

	pipes = init_pipe(parser->count);
	command = parser->cmds;
	while (command)
	{
		if (command->next)
		{
			if (pipe(pipes->tube))
				return (2);
		}
		else if (!ft_strncmp(*command->command, "exit", 5) && command->frst_cmd)
			return (ft_exit(command));
		if (do_fork(command, pipes, env))
			return (2);
		if (!command->lst_cmd && close(pipes->tube[1]))
			return (2);
		if (!command->frst_cmd && close(pipes->in_fd))
			return (2);
		pipes->in_fd = pipes->tube[0];
		command = command->next;
	}
	return (wait_forks(pipes));
}
