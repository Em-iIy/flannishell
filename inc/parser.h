/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/22 13:16:36 by gwinnink      #+#    #+#                 */
/*   Updated: 2022/10/26 19:46:45 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

//----------------------------------------Includes
# include "environment.h"
# include "lexer.h"
# include <stdbool.h>

//----------------------------------------Enums
//----------------------------------------Structs

typedef struct s_file
{
	struct s_file	*next;
	char			*file_name;
	bool			io;
	bool			alt;
}	t_file;

typedef struct s_cmd
{
	struct s_cmd	*next;
	t_file			*files;
	char			**command;
	bool			frst_cmd;
	bool			lst_cmd;
}	t_cmd;

typedef struct s_parser
{
	t_cmd	*cmds;
	int		count;
}	t_parser;
//by default line_n is set to 0 and is not needed

//----------------------------------------Prototypes
t_parser	*parser(t_env *env, t_lexer **lxr);
void		free_parser(t_parser *prsr);


#endif