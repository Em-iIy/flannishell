/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:21:16 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/27 16:32:42 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lexer.h"
#include "lexer_token_utils.h"
#include "libft.h"

static t_lexer	*init_lexer(char *line)
{
	t_lexer	*ret;

	ret = (t_lexer *)malloc(sizeof(t_lexer));
	if (!ret)
		exit(1);
	ret->head = 0;
	ret->line = line;
	ret->quote = -1;
	ret->dquote = -1;
	return (ret);
}

t_lexer	*lexer(char *line)
{
	t_lexer	*lxr;
	int		i;

	lxr = init_lexer(line);
	i = 0;
	while (ft_isspace(line[i]))
		i++;
	while (line[i])
	{
		i = create_next_token(&lxr, i);
	}
	//lexer_token_print(lxr->head);
	if (lxr->dquote == 1 || lxr->quote == 1)
	{
		g_code = 258;
		printf("minishell: syntax error unclosed token\n");
		free(lxr->line);
		free_lexer(&lxr);
		return (NULL);
	}
	return (lxr);
}
