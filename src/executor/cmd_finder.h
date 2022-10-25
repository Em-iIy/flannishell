/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_finder.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 14:20:24 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/10/20 16:35:29 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_FINDER_H
# define CMD_FINDER_H

# include "parser.h"

char	*get_cmd_file(char *command, char **env);
int		cmd_is_builtin(t_cmd *command);

#endif