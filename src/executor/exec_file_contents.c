/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_file_contents.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 18:11:46 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/02 19:08:52 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "parser.h"
#include "libft.h"
#include "executor.h"
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

/*depricated file*/

void	exec_file_contents(char *file, int fd, char **envp)
{
	int			n;
	char		*line;
	t_lexer		*lxr;
	t_parser	*prsr;
	t_env		*env;

	env = env_cpy(envp);
	line = get_next_line(fd);
	if (!line)
		exit (ENOMEM);
	n = 1;
	while (line && *line)
	{
		lxr = lexer(line);
		prsr = parser(env, &lxr);
		g_code = executor(prsr, envp);
		if (g_code == 1 || g_code == 2 || g_code == ENOMEM)
			perror(ft_strjointhree(file, ": line ", ft_itoa(n)));
		free_lexer(&lxr);
		free_parser(prsr);
		free(line);
		line = get_next_line(fd);
		n++;
	}
}
