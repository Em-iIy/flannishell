/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:53:04 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/21 19:09:20 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "environment.h"
#include "libft.h"

int	export_print(char **env);

static void	export_error_msg(char *s1, char *s2)
{
	ft_putstr_fd("minishell: export: `", 2);
	if (s1)
		ft_putstr_fd(s1, 2);
	if (s2)
		ft_putstr_fd(s2, 2);
	g_code = 1;
}

static bool	check_var_name(char	*str)
{
	if (!*str || ft_isdigit(*str))
		return (false);
	while (*str && (*str == '_' || ft_isalnum(*str)))
		str++;
	if (!*str)
		return (true);
	return (false);
}

static void	export_add_env(t_env **env, char *str)
{
	char	*key;
	char	*val;
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (!i)
		i++;
	key = ft_substr(str, 0, i);
	val = NULL;
	if (check_var_name(key) == true)
	{
		if (str[i])
			val = ft_strdup(&str[i + 1]);
		add_env(env, key, val);
		free(val);
	}
	else
		export_error_msg(str, "': not a valid identifier\n");
	free(key);
}

int	ft_export(t_env **env, char **argv)
{
	int	i;

	i = 1;
	g_code = 0;
	while (argv[i] && !*argv[i])
		i++;
	if (!argv[i])
		return (export_print(make_envp(*env)));
	while (argv[i])
	{
		if (*argv[i])
			export_add_env(env, argv[i]);
		i++;
	}
	return (1);
}
