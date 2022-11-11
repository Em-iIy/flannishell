/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/22 16:29:32 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/11 16:54:20 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "enomem.h"
#include "libft.h"
#include "executor_utils.h"
#include "executor.h"
#include "builtins.h"
#include "heredoc.h"
#include "signals.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static int	wait_forks(t_pipe *pipes, t_cmd *cmds)
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
	if (rm_heredoc_files(cmds))
		return (2);
	suppress_sig_output();
	signal(SIGINT, sig_func_parent);
	if (WIFEXITED(status))
		return (check_exit(&status));
	if (WIFSIGNALED(status))
		return (sig_func_child(WTERMSIG(status)));
	return (0);
}

static int	do_fork(t_cmd *command, t_pipe *pipes, t_env **env)
{
	pipes->i++;
	pipes->pid[pipes->i] = fork();
	if (pipes->pid[pipes->i] < 0)
		return (2);
	if (pipes->pid[pipes->i] == 0)
	{
		unsuppress_sig_output();
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		exec_command(command, pipes, env);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	return (0);
}

static int	dont_fork(t_cmd *command, t_env **env)
{
	if (!(command->frst_cmd && command->lst_cmd))
		return (0);
	if (!ft_strncmp(*command->command, "exit", 5))
		return (ft_exit(command));
	if (!ft_strncmp(*command->command, "cd", 3))
		return (ft_cd(env, command->command[1]));
	if (!ft_strncmp(*command->command, "unset", 5))
		return (ft_unset(env, command->command));
	if (!ft_strncmp(*command->command, "export", 7))
		return (ft_export(env, command->command));
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

int	executor(t_parser *parser, t_env **env)
{
	t_cmd		*command;
	t_pipe		*pipes;
	int			error;

	if (!parser->cmds->next && dont_fork(parser->cmds, env))
		return (g_code);
	pipes = init_pipe(parser->count);
	command = parser->cmds;
	while (command)
	{
		if (command->next)
			if (pipe(pipes->tube))
				return (2);
		error = check_heredoc(command->files, *env);
		if (error)
			return (error);
		if (do_fork(command, pipes, env))
			return (2);
		if ((!command->lst_cmd && close(pipes->tube[1]))
			|| (!command->frst_cmd && close(pipes->in_fd)))
			return (2);
		pipes->in_fd = pipes->tube[0];
		command = command->next;
	}
	return (wait_forks(pipes, parser->cmds));
}
