/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:41:50 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/17 19:31:08 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"
#include "parser.h"
#include "parse_io_utils.h"

t_cmd	*cmd_new(void)
{
	t_cmd	*ret;

	ret = (t_cmd *)malloc(sizeof(t_cmd));
	if (!ret)
		exit(ENOMEM);
	ret->next = NULL;
	ret->files = NULL;
	ret->command = NULL;
	return (ret);
}

void	cmd_free(t_cmd *cmd)
{
	if (!cmd)
		return ;
	if (cmd->command)
		ft_free_all(cmd->command);
	if (cmd->files)
		io_free_all(cmd->files);
	free(cmd);
}

t_cmd	*cmd_last(t_cmd *cmd)
{
	if (!cmd)
		return (NULL);
	while (cmd->next)
		cmd = cmd->next;
	return (cmd);
}

void	cmd_add_back(t_cmd **cmd, t_cmd *new)
{
	if (!*cmd)
		*cmd = new;
	else
		cmd_last(*cmd)->next = new;
}

void	cmd_free_all(t_cmd *cmd)
{
	t_cmd	*temp;

	while (cmd)
	{
		temp = cmd->next;
		cmd_free(cmd);
		cmd = temp;
	}
}
