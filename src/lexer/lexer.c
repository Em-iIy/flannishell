/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:21:16 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/17 16:13:30 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include "lexer.h"
#include "lexer_token_utils.h"
#include "libft.h"
#include "error_msg.h"

static t_lexer	*init_lexer(char *line)
{
	t_lexer	*ret;

	ret = (t_lexer *)malloc(sizeof(t_lexer));
	if (!ret)
		exit(ENOMEM);
	ret->head = NULL;
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
		i = create_next_token(&lxr, i);
	if (lxr->dquote == 1 || lxr->quote == 1)
	{
		g_code = 258;
		display_error(NULL, "syntax error unclosed token", NULL, NULL);
		free(lxr->line);
		free_lexer(&lxr);
		return (NULL);
	}
	return (lxr);
}
