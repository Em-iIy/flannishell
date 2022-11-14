/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 14:26:56 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/14 17:39:05 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "parser.h"

void	suppress_sig_output(void);
void	unsuppress_sig_output(void);
void	sig_func_parent(int sig);
int		sig_func_child(int sig);
int		sig_func_heredoc(int sig, t_cmd *cmds);

#endif
