/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:55:58 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/11 12:53:42 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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
		target->val = val;
	}
	else
	{
		new = env_new(NULL);
		new->key = key;
		new->val = val;
		env_add_front(env, new);
	}
}
