/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cd.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 19:06:47 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/11 17:23:02 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "environment.h"
#include "libft.h"

static int	check_error(char *path)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putchar_fd('\n', 2);
	return (1);
}

int	ft_cd(t_env **env, char *path)
{
	char	*old_pwd;
	char	*new_pwd;

	if (!path || !*path)
		path = get_env(*env, "HOME");
	if (!path)
		return (ft_putstr_fd("minishell: cd: HOME not set\n", 2), 1);
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		exit(EXIT_FAILURE);
	if (chdir(path) == -1)
		return (check_error(path));
	new_pwd = getcwd(NULL, 0);
	if (!new_pwd)
		exit(EXIT_FAILURE);
	add_env(env, "OLDPWD", old_pwd);
	add_env(env, "PWD", new_pwd);
	free(old_pwd);
	free(new_pwd);
	return (1);
}
