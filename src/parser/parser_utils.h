/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/22 14:31:11 by gwinnink      #+#    #+#                 */
/*   Updated: 2022/11/14 14:55:32 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_H
# define PARSER_UTILS_H

//----------------------------------------Includes
# include "parser.h"
# include "environment.h"

//----------------------------------------Prototypes
t_parser	*init_parser(void);
char		*parser_expand(t_env *env, char *str);
char		*append_token(t_env *env, char *str, t_token **token);
char		*parse_quote(t_env *env, t_token **token);
char		*parse_dquote(t_env *env, t_token **token);
int			check_valid_str_iden(int iden, char *str);
char		*parse_str(t_env *env, t_token **head);
char		*parse_hd_dlm(t_token **head, bool *hd_quotes);
t_file		*parse_io(t_env *env, t_token **head, int i);
t_cmd		*parse_cmd(t_env *env, t_token **head);

#endif