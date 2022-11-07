/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/05 12:24:19 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/07 19:46:49 by fpurdom       ########   odam.nl         */
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
	char	*hd_name;

	while (files)
	{
		if (files->alt && !files->io)
		{
			hd_name = ft_strjoin("hd_files/", files->file_name);
			if (!hd_name)
				exit (ENOMEM);
			if (open_heredoc(files, hd_name, env))
			{
				free(hd_name);
				return (1);
			}
			free(files->file_name);
			files->file_name = hd_name;
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
				return (2);
			files = files->next;
		}
		commands = commands->next;
	}
	return (0);
}
