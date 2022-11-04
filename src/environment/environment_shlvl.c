/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_shlvl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:10:59 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/03 17:47:50 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "environment.h"

static int	err_msg_shlvl(int lvl)
{
	char	*temp;

	temp = ft_itoa(lvl + 1);
	ft_putstr_fd("minishell: warning: shell level (", 2);
	ft_putstr_fd(temp, 2);
	ft_putstr_fd(") too high, resetting to 1\n", 2);
	free(temp);
	return (1);
}

static int	check_shlvl(char *char_lvl)
{
	int	ret;

	if (!char_lvl)
		return (1);
	if (ft_check_valid_atoi(&ret, char_lvl) == false)
		return (1);
	if (ret == 999)
		return (-1);
	if (ret < 0 || ret == 2147483647)
		return (0);
	if (ret >= 1000 && ret < 2147483647)
		return (err_msg_shlvl(ret));
	return (ret + 1);
}

void	env_shlvl_inc(t_env **env)
{
	int		lvl;
	char	*char_lvl;
	char	*temp;

	char_lvl = get_env(*env, "SHLVL");
	lvl = check_shlvl(char_lvl);
	if (lvl == -1)
		temp = ft_strdup("");
	else
		temp = ft_itoa(lvl);
	add_env(env, "SHLVL", temp);
	free(temp);
}
