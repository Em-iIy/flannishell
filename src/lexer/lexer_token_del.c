/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:13:41 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/04 14:57:36 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lexer_token_utils.h"
#include "lexer.h"

void	lexer_token_del(t_lexer **lxr, t_token *token)
{
	t_token	*prev;
	t_token	*next;

	if (!token)
		return ;
	prev = (token)->prev;
	next = (token)->next;
	if (next && prev)
	{
		prev->next = next;
		next->prev = prev;
	}
	else if (next == NULL && prev)
		prev->next = NULL;
	else if (prev == NULL && next)
	{
		next->prev = NULL;
		(*lxr)->head = next;
	}
	else
		(*lxr)->head = NULL;
	tok_free(&token);
}
