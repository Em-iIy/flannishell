/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:04:32 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/18 21:01:53 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser_utils.h"

/*
returns expanded string from out of double quotes
moves token pointer to closing double quote
*/
char	*parse_quote(t_env *env, t_token **token)
{
	char	*ret;

	ret = ft_calloc(1, 1);
	if ((*token)->iden == QUOTE && (*token)->next)
	{
		(*token) = (*token)->next;
		if ((*token)->iden == EXPAND)
			(*token)->iden = DEF;
	}
	while ((*token)->iden != QUOTE)
	{
		ret = append_token(env, ret, token);
		(*token) = (*token)->next;
	}
	return (ret);
}
