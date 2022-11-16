/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_msg.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 19:18:06 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/16 14:03:29 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# define NO_PERM "Permission denied"
# define NO_FILE "No such file or directory"
# define NO_CMD "command not found"
# define SYNTAX "syntax error near unexpected token `"

int	display_error(char *name, char *msg1, char *msg2, char *msg3);

#endif
