/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:29:08 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/06 16:54:00 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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
		exit(-1);
	ret[i] = NULL;
	i--;
	temp = env;
	while (i >= 0)
	{
		ret[i] = env_to_str(temp);
		temp = temp->next;
		i--;
	}
	return (ret);
}
