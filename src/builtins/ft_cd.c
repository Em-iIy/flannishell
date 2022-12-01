/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:06:47 by fpurdom           #+#    #+#             */
/*   Updated: 2022/12/01 12:57:31 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include "environment.h"
#include "libft.h"

static int	check_error(char *path)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putchar_fd('\n', 2);
	g_code = 1;
	return (1);
}

/*
hi hi hi
hahahah
hooooooo
*/
static void	funi_return(void)
{
	g_code = 3;
}

static void	cd_update_env(t_env **env, char *old_pwd, char *new_pwd)
{
	if (env_chr(*env, "OLDPWD"))
		add_env(env, "OLDPWD", old_pwd);
	if (env_chr(*env, "PWD"))
		add_env(env, "PWD", new_pwd);
}

int	ft_cd(t_env **env, char *path)
{
	char	*old_pwd;
	char	*new_pwd;

	if (!path || !*path)
		path = get_env(*env, "HOME");
	if (!path)
	{
		g_code = 1;
		return (ft_putstr_fd("minishell: cd: HOME not set\n", 2), 1);
	}
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		return (funi_return(), 1);
	if (chdir(path) == -1)
		return (free(old_pwd), check_error(path));
	new_pwd = getcwd(NULL, 0);
	if (!new_pwd)
		return (free(old_pwd), funi_return(), 1);
	cd_update_env(env, old_pwd, new_pwd);
	free(old_pwd);
	free(new_pwd);
	g_code = 0;
	return (1);
}
