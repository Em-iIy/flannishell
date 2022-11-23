/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:20:52 by fpurdom           #+#    #+#             */
/*   Updated: 2022/11/23 13:49:29 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "error_msg.h"
#include "libft.h"
#include "cmd_finder.h"
#include "io_redirector.h"
#include "exec_cmd_utils.h"
#include "builtins.h"
#include "io_redirector.h"
#include "signals.h"
#include "heredoc.h"

int	do_fork(t_cmd *command, t_pipe *pipes, t_env **env)
{
	pipes->i++;
	pipes->pid[pipes->i] = fork();
	if (pipes->pid[pipes->i] < 0)
		return (1);
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

static int	is_unforkable(t_cmd *command)
{
	if (!ft_strncmp(*command->command, "exit", 5))
		return (1);
	if (!ft_strncmp(*command->command, "cd", 3))
		return (2);
	if (!ft_strncmp(*command->command, "unset", 5))
		return (3);
	if (!ft_strncmp(*command->command, "export", 7))
		return (4);
	return (0);
}

static int	exec_unforkable(int cmd, t_cmd *command, t_env **env)
{
	unsuppress_sig_output();
	if (cmd == 1)
		return (ft_exit(command));
	if (cmd == 2)
		return (ft_cd(env, command->command[1]));
	if (cmd == 3)
		return (ft_unset(env, command->command));
	if (cmd == 4)
		return (ft_export(env, command->command));
	return (0);
}

int	dont_fork(t_cmd *command, t_env **env)
{
	int	error;
	int	cmd;
	int	infd;
	int	outfd;

	if (!*command->command)
		return (0);
	cmd = is_unforkable(command);
	if (!cmd)
		return (0);
	error = check_heredoc(command, *env);
	if (error)
		return (error);
	infd = dup(STDIN_FILENO);
	outfd = dup(STDOUT_FILENO);
	if (infd < 0 || outfd < 0)
		return (3);
	error = redirect_io(command);
	if (error)
		return (error);
	error = exec_unforkable(cmd, command, env);
	suppress_sig_output();
	if (redirect_io_back(infd, outfd) || rm_heredoc_files(command))
		return (3);
	return (error);
}

void	exec_command(t_cmd *command, t_pipe *pipes, t_env **env)
{
	char	*cmd_file;
	int		error;

	error = 0;
	dup_everything(command, pipes);
	if (command->files)
	{
		error = redirect_io(command);
		if (error)
			exit (error);
	}
	if (!*command->command)
		exit (g_code);
	if (cmd_is_builtin(command, env))
		exit (g_code);
	if (has_path(*command->command))
		cmd_file = *command->command;
	else
		cmd_file = get_cmd_file(*command->command, *env);
	if (execve(cmd_file, command->command, make_envp(*env)) == -1)
		exit (3);
	exit (0);
}
