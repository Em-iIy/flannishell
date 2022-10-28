/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:20:49 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/27 16:30:38 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>
#include "libft.h"
#include "lexer.h"
#include "parser.h"
#include "environment.h"
#include "executor.h"

/*static void	check_exit(void)
{
	system("leaks --quiet minishell");
}*/

int g_code = 0;

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
	new_envp = make_envp(env);
	//atexit(check_exit);
	while (1)
	{
		line = readline("minishell>");
		if (!line)
			return (0);
		if (line[0] == '\0')
			continue ;
		add_history(line);
		if (!ft_strncmp(line, "exit", 5))
		{
			printf("exit\n");
			exit(0);
		}
		lxr = lexer(line);
		if (!lxr)
			continue ;
		prsr = parser(env, &lxr);
		if (prsr->count != 0)
			g_code = executor(prsr, new_envp);
		if (g_code == 1 || g_code == 2 || g_code == ENOMEM)
			perror("minishell");
		free_lexer(&lxr);
		free_parser(prsr);
		free(line);
	}
}
