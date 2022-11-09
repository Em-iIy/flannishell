/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:01:50 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/09 16:06:40 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "environment.h"

int	ft_env(t_env *env)
{
	while (env)
	{
		printf("%s\n", env->str);
		env = env->next;
	}
	g_code = 0;
	return (1);
}
