/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:44:57 by fpurdom           #+#    #+#             */
/*   Updated: 2022/11/15 17:25:57 by gwinnink         ###   ########.fr       */
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

static void	redirect_input(t_file *file)
{
	int		fd;

	fd = open(file->file_name, O_RDONLY);
	if (fd < 0)
	{
		display_error(file->file_name, "No such file or directory", NULL, NULL);
		exit (1);
	}
	if (dup2(fd, STDIN_FILENO) < 0)
		exit (3);
}

static void	redirect_output(t_file *file)
{
	int	fd;

	if (file->alt)
		fd = open(file->file_name, O_CREAT | O_RDWR | O_APPEND, 0666);
	else
		fd = open(file->file_name, O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fd < 0)
	{
		display_error(file->file_name, "Permission denied", NULL, NULL);
		exit (1);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
		exit (3);
}

void	redirect_io(t_cmd *command)
{
	while (command->files)
	{
		if (command->files->io)
			redirect_output(command->files);
		else
			redirect_input(command->files);
		command->files = command->files->next;
	}
}
