/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 15:12:10 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/10/27 13:28:17 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

char		*gnl_without_n(int fd);
char		*get_next_line(int fd);
char		*make_save(char *static_save, char *buffer);
char		*make_line(char *static_save);
char		*to_next_line(char *old_save);
size_t		s_len(char *str);
int			nl_position(char *str);

#endif
