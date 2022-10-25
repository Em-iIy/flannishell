/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 16:20:52 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/10/20 16:30:32 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_finder.h"
#include "io_redirector.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void	exec_command(t_cmd *command, t_pipe *pipes, char **env)
{
	char	*cmd_file;

	cmd_file = get_cmd_file(*command->command, env);
	if (!command->frst_cmd && dup2(pipes->in_fd, STDIN_FILENO) < 0)
		exit (-1);
	if (!command->lst_cmd && close(pipes->tube[0]))
		exit (-1);
	if (!command->lst_cmd && dup2(pipes->tube[1], STDOUT_FILENO) < 0)
		exit (-1);
	if (!command->lst_cmd && close(pipes->tube[1]))
		exit (-1);
	if (command->files)
		redirect_io(command);
	if (cmd_is_builtin(command))
		exit (0);
	execve(cmd_file, command->command, env);
}
