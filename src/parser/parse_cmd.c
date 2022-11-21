/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:48:40 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/21 13:22:19 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "parse_cmd_utils.h"
#include "parse_io_utils.h"
#include "parser_utils.h"
#include "parser.h"
#include "environment.h"

static int	check_io_iden(int iden)
{
	return (iden == GREAT || iden == GREATGREAT || \
	iden == LESS || iden == LESSLESS);
}

static void	slist_add_n_free(t_env *env, t_token **head, t_str_list **slist)
{
	char	*temp;

	temp = parse_str(env, head);
	ft_str_list_add_front(slist, ft_str_list_new(temp));
	free(temp);
}

t_cmd	*parse_cmd(t_env *env, t_token **head)
{
	t_cmd		*ret;
	t_str_list	*slist;
	t_file		*io_temp;
	int			i;

	i = 0;
	ret = cmd_new();
	slist = NULL;
	while (*head && (*head)->iden != PIPE)
	{
		if (check_io_iden((*head)->iden))
		{
			io_temp = parse_io(env, head, i);
			if (!io_temp)
				return (ft_str_list_free_all(&slist), cmd_free(ret), NULL);
			io_add_back(&ret->files, io_temp);
			i++;
		}
		else if (check_valid_str_iden((*head)->iden, (*head)->content))
			slist_add_n_free(env, head, &slist);
		*head = (*head)->next;
	}
	ret->command = ft_str_list_to_arr(slist);
	ft_str_list_free_all(&slist);
	return (ret);
}
