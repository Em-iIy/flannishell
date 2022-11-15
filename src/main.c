/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:20:49 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/15 16:05:55 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>
#include <signal.h>
#include "libft.h"
#include "lexer.h"
#include "parser.h"
#include "builtins.h"
#include "environment.h"
#include "executor.h"
#include "signals.h"

int	g_code = 0;

static int	lex_parse_exe(t_env *env, char *line)
{
	t_lexer		*lxr;
	t_parser	*prsr;

	lxr = lexer(line);
	if (!lxr)
		return (1);
	prsr = parser(env, &lxr);
	if (prsr->count > 0)
		g_code = executor(prsr, &env);
	if (g_code == 3)
		perror("minishell");
	free_lexer(&lxr);
	free_parser(prsr);
	return (0);
}

static void	minishell(t_env *env)
{
	char		*line;

	while (1)
	{
		line = readline("minishell> ");
		if (!line)
		{
			printf("exit\n");
			exit(g_code);
		}
		if (line[0] == '\0')
			continue ;
		if (lex_parse_exe(env, line))
			continue ;
		add_history(line);
		free(line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char		*line;
	char		**new_envp;
	t_lexer		*lxr;
	t_parser	*prsr;
	t_env		*env;

	(void)argc;
	(void)argv;
	env = env_cpy(envp);
	env_shlvl_inc(&env);
	suppress_sig_output();
	signal(SIGINT, sig_func_parent);
	signal(SIGQUIT, SIG_IGN);
	minishell(env);
}
