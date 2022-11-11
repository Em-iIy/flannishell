/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hd_utils.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 19:04:00 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/11 14:27:00 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HD_UTILS_H
# define HD_UTILS_H

# include "parser.h"

int		open_heredoc(t_file *file, char *hd_name, t_env *env);
char	*create_hd_file(t_file *files);

#endif
