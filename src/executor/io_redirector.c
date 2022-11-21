/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   io_redirector.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:44:57 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/21 15:34:30 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "error_msg.h"
#include "executor_utils.h"
#include "libft.h"

static int	redirect_input(t_file *file)
{
	int		fd;

	fd = open(file->file_name, O_RDONLY);
	if (fd < 0)
		return (display_error(file->file_name, NO_FILE, NULL, NULL));
	if (dup2(fd, STDIN_FILENO) < 0)
		return (3);
	if (close(fd))
		return (3);
	return (0);
}

static int	redirect_output(t_file *file)
{
	int	fd;

	if (file->alt)
		fd = open(file->file_name, O_CREAT | O_RDWR | O_APPEND, 0666);
	else
		fd = open(file->file_name, O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fd < 0)
		return (display_error(file->file_name, NO_PERM, NULL, NULL));
	if (dup2(fd, STDOUT_FILENO) < 0)
		return (3);
	if (close(fd))
		return (3);
	return (0);
}

int	redirect_io(t_cmd *command)
{
	int		error;
	t_file	*files;

	error = 0;
	files = command->files;
	while (files)
	{
		if (files->io)
			error = redirect_output(files);
		else
			error = redirect_input(files);
		if (error)
			return (error);
		files = files->next;
	}
	return (0);
}

int	redirect_io_back(int infd, int outfd)
{
	if (dup2(infd, STDIN_FILENO) < 0)
		return (1);
	if (close(infd))
		return (1);
	if (dup2(outfd, STDOUT_FILENO) < 0)
		return (1);
	if (close(outfd))
		return (1);
	return (0);
}
