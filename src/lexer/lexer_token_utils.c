/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:34:38 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/18 20:54:03 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lexer.h"
#include "libft.h"

int	tok_iden(char *c)
{
	if (c[0] == '\0')
		return (TERM);
	else if (ft_isspace(c[0]))
		return (ISSPACE);
	else if (c[0] == '>')
	{
		if (c[1] == '>')
			return (GREATGREAT);
		return (GREAT);
	}
	else if (c[0] == '<')
	{
		if (c[1] == '<')
			return (LESSLESS);
		return (LESS);
	}
	else if (c[0] == '\'')
		return (QUOTE);
	else if (c[0] == '\"')
		return (DQUOTE);
	else if (c[0] == '|')
		return (PIPE);
	else if (c[0] == '$')
		return (EXPAND);
	return (DEF);
}

t_token	*tok_new(int iden)
{
	t_token	*ret;

	ret = (t_token *)malloc(sizeof(t_token));
	if (!ret)
		exit(1);
	ret->content = NULL;
	ret->next = NULL;
	ret->prev = NULL;
	ret->iden = iden;
	ret->str_end = 0;
	return (ret);
}

int	tok_free(t_token **token)
{
	int	ret;

	ret = (*token)->end_pos;
	free((*token)->content);
	free(*token);
	return (ret);
}

t_token	*tok_last(t_token *token)
{
	if (!token)
		return (NULL);
	while (token->next)
		token = token->next;
	return (token);
}

void	tok_add_back(t_token **token, t_token *new)
{
	t_token	*temp;

	if (!*token)
		*token = new;
	else
	{
		temp = tok_last(*token);
		temp->next = new;
		new->prev = temp;
	}
}
