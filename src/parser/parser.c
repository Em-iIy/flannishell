/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:27:03 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/15 14:49:33 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "parser_utils.h"
#include "parse_cmd_utils.h"
#include "error_msg.h"

// #include <stdlib.h>
// #include <stdio.h>

// static void	print_cmd(t_cmd *cmd)
// {
// 	int		i;
// 	t_file	*file;

// 	i = 0;
// 	file = cmd->files;
// 	if (!cmd)
// 		return ;
// 	printf("cmd: ");
// 	while (cmd->command[i])
// 	{
// 		printf("`%s` ", cmd->command[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	while (file)
// 	{
// 		if (file->io == false)
// 		{
// 			if (file->alt == false)
// 				printf("in: ");
// 			else
// 				printf("hd.: ");
// 		}
// 		else
// 		{
// 			if (file->alt == false)
// 				printf("out: ");
// 			else
// 				printf("app.: ");
// 		}
// 		printf("'%s' =>\t", file->file_name);
// 		file = file->next;
// 	}
// 	printf("\n");
// }

// static void	print_prsr(t_parser *prsr)
// {
// 	t_cmd	*temp;

// 	temp = prsr->cmds;
// 	printf("cmd count: %d", prsr->count);
// 	while (temp)
// 	{
// 		printf("\n-----------------------------------------------------\n");
// 		print_cmd(temp);
// 		temp = temp->next;
// 	}
// }

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
