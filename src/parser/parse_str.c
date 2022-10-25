/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:37:28 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/18 21:02:12 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "parser.h"
#include "parser_utils.h"

int	check_valid_str_iden(int iden, char *str)
{
	if (iden != DEF && \
		iden != QUOTE && \
		iden != DQUOTE && \
		iden != EXPAND)
	{
		printf("minishell: syntax error near unexpected token `%s'\n", str);
		return (0);
	}
	return (1);
}

char	*append_token(t_env *env, char *str, t_token **token)
{
	char	*ret;
	char	*temp;

	if ((*token)->iden == EXPAND && (*token)->next && \
	(*token)->next->iden == DEF)
	{
			temp = parser_expand(env, (*token)->next->content);
			(*token) = (*token)->next;
	}
	else if ((*token)->iden == EXPAND && (*token)->next && \
	(*token)->next && !str)
		temp = ft_strdup("");
	else
		temp = ft_strdup((*token)->content);
	if (!str)
		ret = ft_strdup(temp);
	else
	{
		ret = ft_strjoin(str, temp);
		free(str);
	}
	free(temp);
	return (ret);
}

char	*parse_str(t_env *env, t_token **head)
{
	char	*ret;
	char	*temp_ret;
	char	*temp;

	if (!check_valid_str_iden((*head)->iden, (*head)->content))
		return (NULL);
	ret = ft_calloc(1, 1);
	while ((*head))
	{
		if ((*head)->iden == DQUOTE)
			temp = parse_dquote(env, head);
		else if ((*head)->iden == QUOTE)
			temp = parse_quote(env, head);
		else
			temp = append_token(env, NULL, head);
		temp_ret = ft_strjoin(ret, temp);
		free(ret);
		free(temp);
		ret = temp_ret;
		if ((*head)->str_end == 1)
			return (ret);
		(*head) = (*head)->next;
	}
	return (ret);
}
