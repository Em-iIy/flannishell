/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/05 12:44:40 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/11 13:49:34 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "parser.h"

int	check_heredoc(t_file *file, t_env *env);
int	rm_heredoc_files(t_cmd *commands);

#endif
