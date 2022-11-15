/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:27:03 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/15 17:21:38 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "parser_utils.h"
#include "parse_cmd_utils.h"
#include "error_msg.h"

static bool	check_cmd(t_cmd *cmd, t_token *token)
{
	if ((!*cmd->command && !cmd->files) || \
		(token && token->iden == PIPE && !token->next))
	{
		display_error(NULL, "syntax error near unexpected token `|'",
			NULL, NULL);
		g_code = 258;
		return (false);
	}
	return (true);
}

static void	index_cmds(t_cmd *cmds)
{
	cmds->frst_cmd = true;
	if (cmds->next)
		cmds->lst_cmd = false;
	else
		cmds->lst_cmd = true;
	cmds = cmds->next;
	while (cmds)
	{
		cmds->frst_cmd = false;
		if (cmds->next)
			cmds->lst_cmd = false;
		else
			cmds->lst_cmd = true;
		cmds = cmds->next;
	}
}

t_parser	*parser(t_env *env, t_lexer **lxr)
{
	t_parser	*parser;
	t_cmd		*temp;
	t_token		*tok_temp;

	parser = init_parser();
	tok_temp = (*lxr)->head;
	while (tok_temp && parser->count != -1)
	{
		temp = parse_cmd(env, &tok_temp);
		if (!temp || check_cmd(temp, tok_temp) == false)
		{
			parser->count = -1;
			break ;
		}
		if (tok_temp)
			tok_temp = tok_temp->next;
		parser->count++;
		cmd_add_back(&parser->cmds, temp);
	}
	if (parser->count > 0)
		index_cmds(parser->cmds);
	return (parser);
}
