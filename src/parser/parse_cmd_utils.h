/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:04:51 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/18 12:23:25 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_CMD_UTILS_H
# define PARSE_CMD_UTILS_H

//----------------------------------------Includes
# include "parser.h"

//----------------------------------------Prototypes
t_cmd	*cmd_new(void);
void	cmd_free(t_cmd *cmd);
t_cmd	*cmd_last(t_cmd *cmd);
void	cmd_add_back(t_cmd **cmd, t_cmd *new);
void	cmd_free_all(t_cmd *cmd);

#endif