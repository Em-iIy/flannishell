/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/22 16:20:54 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/10/24 16:22:50 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "parser.h"

typedef struct s_pipe
{
	int	tube[2];
	int	in_fd;
	int	pid_i;
}	t_pipe;

int	executor(t_parser *prsr, char **env);

#endif
