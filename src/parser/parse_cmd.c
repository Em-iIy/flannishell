/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:48:40 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/18 21:00:14 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "parse_cmd_utils.h"
#include "parse_io_utils.h"
#include "parser_utils.h"
#include "parser.h"

static char	*add_cmd(char *cmds, char *new)
{
	char	*ret;
	char	*temp;

	temp = ft_strjoin(cmds, " ");
	if (!temp)
		return (NULL);
	free(cmds);
	ret = ft_strjoin(temp, new);
	if (!ret)
		return (NULL);
	free(temp);
	free(new);
	return (ret);
}

static int	check_io_iden(int iden)
{
	return (iden == GREAT || iden == GREATGREAT || \
	iden == LESS || iden == LESSLESS);
}

static char	**ft_split_n_free(char *str, char c)
{
	char	**ret;

	ret = ft_split(str, c);
	free(str);
	return (ret);
}

static void	*free_n_ret_null(void *ptr)
{
	free(ptr);
	return (NULL);
}

t_cmd	*parse_cmd(t_env *env, t_token **head)
{
	t_cmd	*ret;
	char	*temp;
	t_file	*io_temp;

	temp = (char *)ft_calloc(1, 1);
	ret = cmd_new();
	while (*head && (*head)->iden != PIPE)
	{
		if (check_io_iden((*head)->iden))
		{
			io_temp = parse_io(env, head);
			if (!io_temp)
				return (free_n_ret_null(temp));
			io_add_back(&ret->files, io_temp);
		}
		else if (check_valid_str_iden((*head)->iden, (*head)->content))
		{
			temp = add_cmd(temp, parse_str(env, head));
			if (!temp)
				return (NULL);
		}
		(*head) = (*head)->next;
	}
	ret->command = ft_split_n_free(temp, ' ');
	return (ret);
}
