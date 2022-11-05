/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_io_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 12:38:37 by gwinnink      #+#    #+#                 */
/*   Updated: 2022/11/02 18:09:30 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"

t_file	*io_new(int iden)
{
	t_file	*ret;

	ret = (t_file *)malloc(sizeof(t_file));
	if (!ret)
		exit(-1);
	ret->next = NULL;
	ret->io = false;
	ret->alt = false;
	ret->hd_quotes = false;
	if (iden == GREAT || iden == GREATGREAT)
		ret->io = true;
	if (iden == GREATGREAT || iden == LESSLESS)
		ret->alt = true;
	return (ret);
}

void	io_free(t_file *file)
{
	if (!file)
		return ;
	if (file->file_name)
		free(file->file_name);
	free(file);
}

t_file	*io_last(t_file *file)
{
	if (!file)
		return (NULL);
	while (file->next)
		file = file->next;
	return (file);
}

void	io_add_back(t_file **file, t_file *new)
{
	if (!*file)
		*file = new;
	else
		io_last(*file)->next = new;
}

void	io_free_all(t_file *file)
{
	t_file	*temp;

	while (file)
	{
		temp = file->next;
		io_free(file);
		file = temp;
	}
}
