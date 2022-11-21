/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_cmd_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 12:56:24 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/21 13:06:00 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "error_msg.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

int	has_path(char *command)
{
	int	i;

	i = ft_strlen(command) - 1;
	while (i >= 0 && command[i] != 47)
		i--;
	if (i < 0)
		return (false);
	if (access(command, F_OK) == -1)
		exit (display_error(command, NO_FILE, NULL, NULL) + 126);
	else if (access(command, X_OK) == -1)
		exit (display_error(command, NO_PERM, NULL, NULL) + 125);
	return (true);
}

void	dup_everything(t_cmd *command, t_pipe *pipes)
{
	if (!command->frst_cmd && dup2(pipes->in_fd, STDIN_FILENO) < 0)
		exit (3);
	if (!command->lst_cmd && close(pipes->tube[0]))
		exit (3);
	if (!command->lst_cmd && dup2(pipes->tube[1], STDOUT_FILENO) < 0)
		exit (3);
	if (!command->lst_cmd && close(pipes->tube[1]))
		exit (3);
}
