/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/22 16:20:54 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/02 14:44:42 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "parser.h"

typedef struct s_pipe
{
	int	tube[2];
	int	*pid;
	int	in_fd;
	int	i;
}	t_pipe;

int	executor(t_parser *prsr, t_env *env);

#endif
