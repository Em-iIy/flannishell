/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:10:59 by fpurdom           #+#    #+#             */
/*   Updated: 2022/11/04 14:58:55 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "parser.h"

int	ft_echo(char **strs);
int	ft_exit(t_cmd *command);
int	ft_env(t_env *env);
int	ft_pwd(void);

#endif
