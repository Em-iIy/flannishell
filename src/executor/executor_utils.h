/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor_utils.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 16:22:04 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/10/20 16:35:52 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_UTILS_H
# define EXECUTOR_UTILS_H

# include "parser.h"
# include "executor.h"

void	exec_command(t_cmd *command, t_pipe *pipes, char **env);

#endif