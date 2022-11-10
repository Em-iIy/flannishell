/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:20:54 by fpurdom           #+#    #+#             */
/*   Updated: 2022/11/10 16:06:45 by gwinnink         ###   ########.fr       */
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

int	executor(t_parser *prsr, t_env **env);

#endif
