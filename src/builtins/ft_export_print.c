/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:01:40 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/10 15:02:57 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	arr_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

static void	export_sort(char **env)
{
	int	i;
	int	j;

	if (!env)
		exit (EXIT_FAILURE);
	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[j] && env[j + 1])
		{
			if (ft_strncmp(env[j], env[j + 1], ft_strlen(env[j] + 1)) > 0)
				arr_swap(&env[j], &env[j + 1]);
			j++;
		}
		i++;
	}
}

static void	export_printf(char *str)
{
	char	*key;
	char	*val;
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	key = ft_substr(str, 0, i + 1);
	val = ft_strdup(&str[i + 1]);
	printf("declare -x %s\"%s\"\n", key, val);
	free(key);
	free(val);
}

int	export_print(char **env)
{
	int	i;

	i = 0;
	export_sort(env);
	while (env[i])
	{
		export_printf(env[i]);
		i++;
	}
	ft_free_all(env);
	return (1);
}
