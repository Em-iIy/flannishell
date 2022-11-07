/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:55:58 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/03 18:26:05 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "environment_utils.h"
#include "environment.h"

void	add_env(t_env **env, char *key, char *val)
{
	t_env	*target;
	char	*temp;

	if (!key || !val)
		return ;
	target = env_chr(*env, key);
	if (target)
	{
		free(target->val);
		free(target->str);
		target->val = ft_strdup(val);
		target->str = ft_strjointhree(target->key, "=", target->val);
	}
	else
	{
		temp = ft_strjointhree(key, "=", val);
		env_add_front(env, env_new(temp));
		free(temp);
	}
}
