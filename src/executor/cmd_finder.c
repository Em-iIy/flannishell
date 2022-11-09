/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_finder.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 14:17:19 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/09 13:16:26 by fpurdom       ########   odam.nl         */
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

static void	cmd_not_found(char **to_free, char *cmd_file, char *command)
{
	printf("minishell: %s: command not found\n", command);
	ft_free_all(to_free);
	free(cmd_file);
	exit (127);
}

static void	permission_denied(char **to_free, char *cmd_file, char *command)
{
	printf("minishell: %s: Permission denied\n", command);
	if (to_free)
		ft_free_all(to_free);
	if (cmd_file)
		free(cmd_file);
	exit (126);
}

static char	**find_path(t_env *env, char *command)
{
	char	*val;
	char	**paths;

	val = get_env(env, "PATH");
	if (!val)
	{
		printf("minishell: %s: No such file or directory\n", command);
		exit(127);
	}
	paths = ft_split(val, ':');
	if (!paths)
		exit (ENOMEM);
	return (paths);
}

char	*get_cmd_file(char *command, t_env *env)
{
	char	**paths;
	char	**to_free;
	char	*cmd_file;

	paths = find_path(env, command);
	cmd_file = ft_strdup(command);
	if (!cmd_file)
		exit (ENOMEM);
	to_free = paths;
	while (access(cmd_file, F_OK) == -1 && *paths)
	{
		free(cmd_file);
		cmd_file = ft_strjointhree(*paths, "/", command);
		paths++;
	}
	if (access(cmd_file, F_OK) == 0 && access(cmd_file, X_OK) == -1)
		permission_denied(to_free, cmd_file, command);
	if (!*paths)
		cmd_not_found(to_free, cmd_file, command);
	ft_free_all(to_free);
	return (cmd_file);
}

int	cmd_is_builtin(t_cmd *command, t_env *env)
{
	if (!ft_strncmp(*command->command, "echo", 5))
		return (ft_echo(command->command + 1));
	if (!ft_strncmp(*command->command, "exit", 5))
		return (ft_exit(command));
	if (!ft_strncmp(*command->command, "cd", 3))
		return (ft_cd(env, command->command[1]));
	if (!ft_strncmp(*command->command, "pwd", 4))
		return (ft_pwd());
	if (!ft_strncmp(*command->command, "env", 4))
		return (ft_env(env));
	return (0);
	/*else if (!ft_strncmp(*command->command, "export", 7))
		return (ft_export());
	else if (!ft_strncmp(*command->command, "unset", 6))
		return (ft_unset());
	else
		return (0);*/
}
