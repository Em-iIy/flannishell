/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:20:52 by fpurdom           #+#    #+#             */
/*   Updated: 2022/11/10 16:05:33 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cmd_finder.h"
#include "io_redirector.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

static int	has_path(char *command)
{
	int	i;

	i = ft_strlen(command) - 1;
	while (i >= 0 && command[i] != 47)
		i--;
	if (i < 0)
		return (false);
	if (access(command, F_OK) == -1)
	{
		printf("minishell: %s: No such file or directory\n", command);
		exit (127);
	}
	else if (access(command, X_OK) == -1)
	{
		printf("minishell: %s: Permission denied\n", command);
		exit (126);
	}
	return (true);
}

void	exec_command(t_cmd *command, t_pipe *pipes, t_env **env)
{
	char	*cmd_file;
	int		fd;

	if (!command->frst_cmd && dup2(pipes->in_fd, STDIN_FILENO) < 0)
		exit (2);
	if (!command->lst_cmd && close(pipes->tube[0]))
		exit (2);
	if (!command->lst_cmd && dup2(pipes->tube[1], STDOUT_FILENO) < 0)
		exit (2);
	if (!command->lst_cmd && close(pipes->tube[1]))
		exit (2);
	if (command->files)
		redirect_io(command);
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
