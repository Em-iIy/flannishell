/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:23:30 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/04 13:59:37 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_TOKEN_UTILS_H
# define LEXER_TOKEN_UTILS_H

//----------------------------------------Includes
# include "lexer.h"

//----------------------------------------Prototypes
int		tok_iden(char *c);
t_token	*tok_new(int iden);
t_token	*tok_last(t_token *token);
void	tok_add_back(t_token **token, t_token *new);
void	print_list_tokens(t_token *head);
void	lexer_token_print(t_token *token);
int		tok_free(t_token **token);
void	lexer_token_del(t_lexer **lxr, t_token *token);

#endif