/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/05 12:24:19 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/16 19:20:43 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "enomem.h"
#include "hd_utils.h"
#include "signals.h"

static int	hd_fork(char *delimiter, t_file *files, t_cmd *cmds, t_env *env)
{
	int	status;

	if (fork() == 0)
		exit (open_heredoc(files, delimiter, env));
	signal(SIGINT, SIG_IGN);
	wait(&status);
	signal(SIGINT, sig_func_parent);
	if (WIFEXITED(status))
		if (WEXITSTATUS(status))
			return (check_memory(&status));
	if (WIFSIGNALED(status))
		return (sig_func_heredoc(WTERMSIG(status), cmds));
	return (0);
}

int	check_heredoc(t_cmd *cmds, t_env *env)
{
	int		error;
	char	*delimiter;
	t_file	*files;

	files = cmds->files;
	while (files)
	{
		if (files->alt && !files->io)
		{
			delimiter = create_hd_file(files);
			error = hd_fork(delimiter, files, cmds, env);
			free(delimiter);
			if (error)
				return (error);
		}
		files = files->next;
	}
	return (0);
}

int	rm_heredoc_files(t_cmd *commands)
{
	t_file	*files;

	while (commands)
	{
		files = commands->files;
		while (files)
		{
			if (access(files->file_name, F_OK) == 0)
				if (files->alt && !files->io && unlink(files->file_name))
					return (1);
			files = files->next;
		}
		commands = commands->next;
	}
	return (0);
}
