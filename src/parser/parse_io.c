/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:32:18 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/27 14:52:17 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "parser_utils.h"
#include "parser.h"

static t_file	*file_init(int iden)
{
	t_file	*ret;

	ret = (t_file *)malloc(sizeof(t_file));
	if (!ret)
		exit(-1);
	ret->next = NULL;
	ret->io = false;
	ret->alt = false;
	if (iden == GREAT || iden == GREATGREAT)
		ret->io = true;
	if (iden == GREATGREAT || iden == LESSLESS)
		ret->alt = true;
	return (ret);
}

t_file	*parse_io(t_env *env, t_token **head)
{
	t_file	*ret;
	t_token	*temp_head;
	char	*temp;

	temp_head = (*head);
	if ((*head)->next == NULL)
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		g_code = 258;
		return (NULL);
	}
	else
	{
		(*head) = (*head)->next;
		temp = parse_str(env, head);
		if (!temp)
			return (NULL);
	}
	ret = file_init(temp_head->iden);
	ret->file_name = temp;
	return (ret);
}
