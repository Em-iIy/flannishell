/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_finder.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 14:17:19 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/16 13:57:53 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "libft.h"
#include "parser.h"
#include "builtins.h"
#include "environment.h"
#include "error_msg.h"

static void	cmd_not_found(char **to_free, char *cmd_file, char *command)
{
	ft_free_all(to_free);
	free(cmd_file);
	exit (display_error(command, NO_CMD, NULL, NULL) + 126);
}

static void	permission_denied(char **to_free, char *cmd_file, char *command)
{
	if (to_free)
		ft_free_all(to_free);
	if (cmd_file)
		free(cmd_file);
	exit (display_error(command, NO_PERM, NULL, NULL) + 125);
}

static char	**find_path(t_env *env, char *command)
{
	char	*val;
	char	**paths;

	val = get_env(env, "PATH");
	if (!val)
	{
		display_error(command, NO_FILE, NULL, NULL);
		exit(127);
	}
	paths = ft_split(val, ':');
	if (!paths)
		exit (ENOMEM);
	return (paths);
}

// lemme know if this works as it should
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
	while (*paths)
	{
		free(cmd_file);
		cmd_file = ft_strjointhree(*paths, "/", command);
		if (access(cmd_file, F_OK) != -1)
			break ;
		paths++;
	}
	if (access(cmd_file, F_OK) == 0 && access(cmd_file, X_OK) == -1)
		permission_denied(to_free, cmd_file, command);
	if (!*paths)
		cmd_not_found(to_free, cmd_file, command);
	ft_free_all(to_free);
	return (cmd_file);
}

int	cmd_is_builtin(t_cmd *command, t_env **env)
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
		return (ft_env(*env));
	if (!ft_strncmp(*command->command, "unset", 6))
		return (ft_unset(env, command->command));
	if (!ft_strncmp(*command->command, "export", 7))
		return (ft_export(env, command->command));
	return (0);
}
