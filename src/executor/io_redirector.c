/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   io_redirector.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:44:57 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/09 17:01:44 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor_utils.h"
#include "libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

static void	redirect_input(t_file *file)
{
	int		fd;

	fd = open(file->file_name, O_RDONLY);
	if (fd < 0)
	{
		printf("minishell: %s: No such file or directory\n", file->file_name);
		exit (1);
	}
	if (dup2(fd, STDIN_FILENO) < 0)
		exit (2);
}

static void	redirect_output(t_file *file)
{
	int	fd;

	if (file->alt)
		fd = open(file->file_name, O_CREAT | O_RDWR | O_APPEND, 0666);
	else
		fd = open(file->file_name, O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fd < 0)
		exit (2);
	//need to add error message here
	if (dup2(fd, STDOUT_FILENO) < 0)
		exit (2);
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
