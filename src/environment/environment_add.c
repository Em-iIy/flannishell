/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:55:58 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/27 17:39:07 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "environment_utils.h"
#include "environment.h"

void	add_env(t_env **env, char *key, char *val)
{
	t_env	*target;
	t_env	*new;

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
		env_add_front(env, env_new(ft_strjointhree(new->key, "=", new->val)));
}
