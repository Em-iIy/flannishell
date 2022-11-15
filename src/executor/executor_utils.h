/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:22:04 by fpurdom           #+#    #+#             */
/*   Updated: 2022/11/15 17:34:39 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_UTILS_H
# define EXECUTOR_UTILS_H

# include "parser.h"
# include "executor.h"

void	exec_command(t_cmd *command, t_pipe *pipes, t_env **env);
void	free_pipes(t_pipe *pipes);

#endif