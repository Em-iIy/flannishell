/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:29:08 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/21 13:01:57 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"
#include "environment.h"
#include "environment_utils.h"

t_env	*env_cpy(char **envp)
{
	t_env	*ret;

	ret = NULL;
	while (*envp)
	{
		env_add_front(&ret, env_new(*envp));
		envp++;
	}
	return (ret);
}

char	**make_envp(t_env *env)
{
	char	**ret;
	t_env	*temp;
	int		i;

	i = 0;
	temp = env;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	ret = (char **)malloc((i + 1) * sizeof(char *));
	if (!ret)
		exit(ENOMEM);
	ret[i] = NULL;
	i--;
	temp = env;
	while (i >= 0)
	{
		ret[i] = ft_strdup(temp->str);
		temp = temp->next;
		i--;
	}
	return (ret);
}
