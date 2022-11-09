/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_finder.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 14:20:24 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/09 13:03:13 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_FINDER_H
# define CMD_FINDER_H

# include "parser.h"
# 

char	*get_cmd_file(char *command, t_env *env);
int		cmd_is_builtin(t_cmd *command, t_env *env);

#endif