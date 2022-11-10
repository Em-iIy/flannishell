/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 14:26:56 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/10 16:01:03 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

void	suppress_sig_output(void);
void	unsuppress_sig_output(void);
void	sig_func_parent(int sig);
void	sig_func_child(int sig);

#endif
