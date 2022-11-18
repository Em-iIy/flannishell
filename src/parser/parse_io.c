/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:32:18 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/17 16:46:20 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <errno.h>
#include "parser_utils.h"
#include "parser.h"
#include "error_msg.h"

static t_file	*file_init(int iden, int i)
{
	t_file	*ret;

	ret = (t_file *)malloc(sizeof(t_file));
	if (!ret)
		exit(ENOMEM);
	ret->next = NULL;
	ret->io = false;
	ret->alt = false;
	if (iden == GREAT || iden == GREATGREAT)
		ret->io = true;
	if (iden == GREATGREAT || iden == LESSLESS)
		ret->alt = true;
	ret->i = i;
	return (ret);
}

t_file	*parse_io(t_env *env, t_token **head, int i)
{
	t_file	*ret;
	t_token	*temp_head;
	char	*temp;
	bool	hd_quotes;

	temp_head = *head;
	hd_quotes = false;
	if ((*head)->next == NULL)
	{
		display_error(NULL, SYNTAX, "newline'", NULL);
		g_code = 258;
		return (NULL);
	}
	*head = (*head)->next;
	if (temp_head->iden == LESSLESS)
		temp = parse_hd_dlm(head, &hd_quotes);
	else
		temp = parse_str(env, head);
	if (!temp)
		return (NULL);
	ret = file_init(temp_head->iden, i);
	ret->hd_quotes = hd_quotes;
	ret->file_name = temp;
	return (ret);
}
