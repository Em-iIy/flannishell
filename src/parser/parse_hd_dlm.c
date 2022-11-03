/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hd_dlm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:22:36 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/02 19:56:26 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdbool.h>
#include "environment.h"
#include "parser_utils.h" // ?
#include "parser.h"
#include "libft.h"

static char	*parse_hd_quotes(t_token **token, int quote)
{
	char	*ret;
	char	*temp;

	ret = ft_calloc(1, 1);
	if ((*token)->iden == quote && (*token)->next)
		*token = (*token)->next;
	while ((*token)->iden != quote)
	{
		temp = ft_strjoin(ret, (*token)->content);
		free(ret);
		ret = temp;
		*token = (*token)->next;
	}
	return (ret);
}

char	*parse_hd_dlm(t_token **head, bool *hd_quotes)
{
	char	*ret;
	char	*temp;

	if (!check_valid_str_iden((*head)->iden, (*head)->content))
		return (NULL);
	ret = ft_calloc(1, 1);
	while (*head)
	{
		if ((*head)->iden == DQUOTE || (*head)->iden == QUOTE)
		{
			temp = ft_strjoin(ret, parse_hd_quotes(head, (*head)->iden));
			*hd_quotes = true;
		}
		else if ((*head)->iden == EXPAND && (*head)->next && \
				(*head)->next->iden == DEF)
		{
			temp = ft_strjointhree(ret, (*head)->content, \
					(*head)->next->content);
			*head = (*head)->next;
		}
		else if ((*head)->iden == EXPAND && (*head)->next && (*head)->next)
			temp = ft_strdup("");
		else
			temp = ft_strjoin(ret, (*head)->content);
		free(ret);
		ret = temp;
		if ((*head)->str_end == 1)
			return (ret);
		*head = (*head)->next;
	}
	return (ret);
}
