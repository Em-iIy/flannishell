/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:20:20 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/15 16:35:55 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

//----------------------------------------Enums
enum e_iden
{
	TERM = -1,
	ISSPACE,
	GREAT,
	GREATGREAT,
	LESS,
	LESSLESS,
	QUOTE,
	DQUOTE,
	PIPE,
	EXPAND,
	DEF
};

//----------------------------------------Structs
typedef struct s_token
{
	int				iden;
	int				end_pos;
	int				start_pos;
	int				str_end;
	char			*content;
	struct s_token	*next;	
	struct s_token	*prev;	
}	t_token;

typedef struct s_lexer
{
	t_token			*head;
	char			*line;
	int				quote;
	int				dquote;
}	t_lexer;

//----------------------------------------Prototypes
t_lexer	*lexer(char *line);
int		create_next_token(t_lexer **lxr, int pos);
void	free_lexer(t_lexer **lxr);

extern int	g_code;

#endif