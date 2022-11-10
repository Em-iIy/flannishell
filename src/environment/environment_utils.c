/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:25:55 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/10 18:21:57 by gwinnink         ###   ########.fr       */
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
	ret->str = NULL;
	ret->key = NULL;
	ret->val = NULL;
	ret->next = NULL;
	if (!str)
		return (ret);
	ret->str = ft_strdup(str);
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] != '=')
		return (ret);
	ret->key = ft_substr(str, 0, i);
	ret->val = ft_strdup(&str[i + 1]);
	return (ret);
}

void	env_add_front(t_env **env, t_env *new)
{
	new->next = *env;
	*env = new;
}

void	env_free(t_env *env)
{
	free(env->str);
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
		return ;
	}
	while (head->next != del)
		head = head->next;
	head->next = del->next;
	env_free(del);
}

void	env_free_all(t_env **head)
{
	t_env	*temp;

	while (*head)
	{
		temp = (*head)->next;
		env_free(*head);
		*head = temp;
	}
}
