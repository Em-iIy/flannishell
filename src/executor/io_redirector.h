/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   io_redirector.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:45:57 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/21 13:34:41 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_REDIRECTOR_H
# define IO_REDIRECTOR_H

# include "executor_utils.h"

int	redirect_io(t_cmd *command);
int	redirect_io_back(int infd, int outfd);

#endif