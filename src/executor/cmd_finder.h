/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_finder.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:20:24 by fpurdom           #+#    #+#             */
/*   Updated: 2022/11/10 11:28:30 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_FINDER_H
# define CMD_FINDER_H

# include "parser.h"

char	*get_cmd_file(char *command, t_env *env);
int		cmd_is_builtin(t_cmd *command, t_env *env);

#endif