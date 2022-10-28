/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:25:55 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/27 18:59:53 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

//----------------------------------------Structs
typedef struct s_env
{
	struct s_env	*next;
	char			*str;
	char			*key;
	char			*val;
}	t_env;

//----------------------------------------Prototypes
t_env	*env_cpy(char **envp);
char	**make_envp(t_env *env);

t_env	*env_chr(t_env *env, char *key);
char	*get_env(t_env *env, char *key);

void	add_env(t_env **env, char *key, char *val);
void	unset_env(t_env **env, char *key);

t_env	*env_new(char *str);
void	env_add_front(t_env **env, t_env *new);

void	env_free_all(t_env **head);

extern int	g_code;

#endif