/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:14:19 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/09 16:05:57 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "libft.h"

#include "builtins.h"

static int	unset_error_msg(char *s1, char *s2)
{
	ft_putstr_fd("minishell: unset: ", 2);
	if (s1)
		ft_putstr_fd(s1, 2);
	if (s2)
		ft_putstr_fd(s2, 2);
	g_code = 1;
	return (1);
}

static bool	check_var_name(char	*str)
{
	while (*str && (*str == '_' || ft_isalnum(*str)))
		str++;
	if (!*str)
		return (true);
	return (false);
}

int	ft_unset(t_env *env, char **argv)
{
	int	i;

	i = 1;
	g_code = 0;
	while (argv[i])
	{
		if (check_var_name(argv[i]) == false)
			unset_error_msg(argv[i], ": not a valid identifier\n");
		else
			unset_env(&env, argv[i]);
		i++;
	}
	return (1);
}
