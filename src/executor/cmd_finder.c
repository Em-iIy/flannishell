/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_finder.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 14:17:19 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/10/21 15:27:59 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "builtins.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

static char	*cmd_not_found(char **to_free, char *cmd_file, char *command)
{
	printf("minishell: %s: command not found\n", command);
	ft_free_all(to_free);
	free(cmd_file);
	exit (127);
}

static char	**get_paths(char **env)
{
	while (*env && ft_strncmp("PATH=", *env, 5))
		env++;
	return (ft_split(*env, ':'));
}

char	*get_cmd_file(char *command, char **env)
{
	char	**paths;
	char	**to_free;
	char	*cmd_file;
	char	*temp;

	paths = get_paths(env);
	cmd_file = ft_strdup(command);
	if (!paths || !cmd_file)
		exit (ENOMEM);
	to_free = paths;
	while (access(cmd_file, X_OK) == -1 && *paths)
	{
		free(cmd_file);
		temp = ft_strjoin(*paths, "/");
		cmd_file = ft_strjoin(temp, command);
		if (!temp || !cmd_file)
			exit (ENOMEM);
		free(temp);
		paths++;
	}
	if (!*paths)
		cmd_not_found(to_free, cmd_file, command);
	ft_free_all(to_free);
	return (cmd_file);
}

int	cmd_is_builtin(t_cmd *command)
{
	if (!ft_strncmp(*command->command, "echo", 5))
		return (ft_echo(command->command + 1));
	return (0);
	/*else if (!ft_strncmp(*command->command, "cd", 2))
		return (ft_cd());
	else if (!ft_strncmp(*command->command, "pwd", 3))
		return (ft_pwd());
	else if (!ft_strncmp(*command->command, "export", 6))
		return (ft_export());
	else if (!ft_strncmp(*command->command, "unset", 5))
		return (ft_unset());
	else if (!ft_strncmp(*command->command, "env", 3))
		return (ft_env());
	else
		return (0);*/
}
