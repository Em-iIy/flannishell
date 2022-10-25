/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   environment.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 15:25:55 by gwinnink      #+#    #+#                 */
/*   Updated: 2022/10/24 16:22:18 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

//----------------------------------------Structs
typedef struct s_env
{
	struct s_env	*next;
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

extern int	g_code;

#endif