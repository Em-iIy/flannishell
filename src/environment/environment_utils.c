/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:25:55 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/11 12:20:12 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "environment.h"

t_env	*env_new(char *str)
{
	t_env	*ret;
	int		i;

	ret = (t_env *)malloc(sizeof(t_env));
	if (!ret)
		exit(-1);
	ret->key = NULL;
	ret->val = NULL;
	ret->next = NULL;
	if (str)
	{
		i = 0;
		while (str[i] && str[i] != '=')
			i++;
		ret->key = ft_substr(str, 0, i);
		ret->val = ft_strdup(&str[i + 1]);
	}
	return (ret);
}

char	*env_to_str(t_env *env)
{
	char	*temp;
	char	*ret;

	temp = ft_strjoin(env->key, "=");
	ret = ft_strjoin(temp, env->val);
	free(temp);
	return (ret);
}

void	env_add_front(t_env **env, t_env *new)
{
	new->next = *env;
	*env = new;
}

void	env_free(t_env *env)
{
	free(env->key);
	free(env->val);
	free(env);
}

void	env_del(t_env **env, t_env *del)
{
	t_env	*head;

	head = *env;
	if (del == head)
	{
		*env = del->next;
		env_free(del);
	}
	while (head->next != del)
		head = head->next;
	head->next = del->next;
	env_free(del);
}
