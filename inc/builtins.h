/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:10:59 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/09 13:00:35 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "parser.h"

int	ft_echo(char **strs);
int	ft_exit(t_cmd *command);
int	ft_cd(t_env *env, char *path);
int	ft_pwd(void);
int	ft_env(t_env *env);

#endif
