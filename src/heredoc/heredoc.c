/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/05 12:24:19 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/11 14:25:30 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hd_utils.h"
#include "libft.h"
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int	check_heredoc(t_file *files, t_env *env)
{
	int		fd;
	int		status;
	char	*delimiter;

	while (files)
	{
		if (files->alt && !files->io)
		{
			delimiter = create_hd_file(files);
			if (fork() == 0)
			{
				if (open_heredoc(files, delimiter, env))
					exit (2);
				exit (0);
			}
			signal(SIGINT, SIG_IGN);
			wait(&status);
			signal(SIGINT, SIG_DFL);
			if (WIFEXITED(status))
				return (WEXITSTATUS(status));
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
			if (files->alt && !files->io && unlink(files->file_name))
				return (1);
			files = files->next;
		}
		commands = commands->next;
	}
	return (0);
}
