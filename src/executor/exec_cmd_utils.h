/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_cmd_utils.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 12:59:01 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/21 14:39:20 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_CMD_UTILS_H
# define EXEC_CMD_UTILS_H

# include "executor.h"

int		has_path(char *command);
void	dup_everything(t_cmd *command, t_pipe *pipes);

#endif
