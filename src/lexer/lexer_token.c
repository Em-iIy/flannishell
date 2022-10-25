/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:22:49 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/18 20:47:58 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_token_utils.h"
#include "lexer.h"
#include "libft.h"

/* --find_next_token
Will loop until it finds then next relevent token

if within DOUBLE QUOTES
	loop over all:
		SPACES
		DEFAULT
		SINGLE QUOTES

if within SINGLE QUOTES
	loop until next:
		SINGLE QUOTE

else
	loop over all:
		DEFAULT
Thanks norminette for making this function unreadable and very inefficient :)
*/
static int	find_next_token(t_lexer *lxr, int i)
{
	if (lxr->dquote == 1)
		while (tok_iden(&lxr->line[i]) != TERM && \
		tok_iden(&lxr->line[i]) != DQUOTE && \
		tok_iden(&lxr->line[i]) != EXPAND)
			i++;
	else if (lxr->quote == 1)
		while (tok_iden(&lxr->line[i]) != TERM && \
		tok_iden(&lxr->line[i]) != QUOTE)
			i++;
	else
		while (tok_iden(&lxr->line[i]) != TERM && \
		(tok_iden(&lxr->line[i]) == DEF))
			i++;
	return (i);
}

static void	fill_token(t_lexer **lxr, t_token **token,
						int start_pos, size_t n)
{
	char	*temp;

	temp = ft_substr((*lxr)->line, start_pos, n);
	if ((*lxr)->dquote == -1 && (*lxr)->quote == -1)
	{
		(*token)->content = ft_strtrim(temp, "\t\n\v\f\r ");
		if (*(*token)->content == '\0')
		{
			(*token)->iden = -2;
		}
		free(temp);
	}
	else
		(*token)->content = temp;
	(*token)->start_pos = start_pos;
	(*token)->end_pos = start_pos + n;
}

static void	check_end(t_lexer *lexer, t_token *token)
{
	char	*end;
	int		end_iden;

	end = &lexer->line[token->end_pos];
	if (token->iden == DEF)
		if (tok_iden(&lexer->line[token->end_pos - 1]) != DEF)
			end = &lexer->line[token->end_pos - 1];
	end_iden = tok_iden(end);
	if (end_iden == EXPAND || end_iden == QUOTE || end_iden == DQUOTE)
		return ;
	if (lexer->dquote == 1 || lexer->quote == 1)
		return ;
	token->str_end = 1;
}

/*
This one's just here because create_next_token() was getting too long
*/
static int	spec_char_token(t_lexer **lxr, t_token **new, int pos)
{
	if (((*new)->iden != DEF && (*new)->iden != ISSPACE) && \
	((*lxr)->quote == -1 || ((*new)->iden == QUOTE && \
	(*lxr)->dquote == -1)) && ((*lxr)->dquote == -1 || \
	((*new)->iden == EXPAND && (*lxr)->dquote == 1) || \
	((*new)->iden == DQUOTE && (*lxr)->dquote == 1)))
	{
		if ((*new)->iden == DQUOTE)
			(*lxr)->dquote *= -1;
		else if ((*new)->iden == QUOTE)
			(*lxr)->quote *= -1;
		if ((*new)->iden == GREATGREAT || (*new)->iden == LESSLESS)
			fill_token(lxr, new, pos, 2);
		else
			fill_token(lxr, new, pos, 1);
		return (1);
	}
	return (0);
}

int	create_next_token(t_lexer **lxr, int pos)
{
	t_token	*new;
	int		i;

	i = 0;
	new = tok_new(tok_iden(&(*lxr)->line[pos]));
	if (!spec_char_token(lxr, &new, pos))
	{
		i = find_next_token(*lxr, i + pos) - pos;
		fill_token(lxr, &new, pos, i);
		while (ft_isspace((*lxr)->line[new->end_pos]))
			new->end_pos++;
	}
	if (new->iden == -2)
	{
		i = new->end_pos;
		tok_free(&new);
		return (i);
	}
	check_end(*lxr, new);
	tok_add_back(&(*lxr)->head, new);
	return (new->end_pos);
}
