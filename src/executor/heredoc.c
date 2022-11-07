/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/05 12:24:19 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/07 15:53:00 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <readline/readline.h>
#include <unistd.h>

static int	open_heredoc(t_file *file, char *hd_name)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(hd_name, O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fd < 0)
		return (1);
	while (1)
	{
		line = readline(">");
		if (!line)
			exit (0);
		if (line[0] == '\0')
			continue ;
		if (!ft_strncmp(file->file_name, line, ft_strlen(line) + 1))
			break ;
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	free(line);
	if (close(fd))
		return (1);
	return (0);
}

int	check_heredoc(t_file *files)
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
			if (open_heredoc(files, hd_name))
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
			if (files->alt && !files->io)
			{
				if (unlink(files->file_name))
					return (2);
			}
			files = files->next;
		}
		commands = commands->next;
	}
	return (0);
}
