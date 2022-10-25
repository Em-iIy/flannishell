/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_unset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:01:47 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/11 13:07:24 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment_utils.h"
#include "environment.h"

void	unset_env(t_env **env, char *key)
{
	t_env	*target;

	if (!key)
		return ;
	target = env_chr(*env, key);
	if (!target)
		return ;
	env_del(env, target);
}
