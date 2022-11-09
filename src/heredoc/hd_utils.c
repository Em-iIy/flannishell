/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hd_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 19:03:57 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/08 12:25:58 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <fcntl.h>
#include <unistd.h>

static int	hd_expand(char *line, int fd, t_env *env)
{
	int		i;
	char	*key;
	char	*env_var;

	i = 0;
	while (line[i] && ft_isalnum(line[i]))
			i++;
	key = ft_substr(line, 0, i);
	env_var = get_env(env, key);
	free(key);
	if (env_var)
		ft_putstr_fd(env_var, fd);
	return (i);
}

static void	write_to_file(t_file *file, char *line, int fd, t_env *env)
{
	int		i;
	char	*env_var;

	i = 0;
	if (file->hd_quotes)
	{
		ft_putstr_fd(line, fd);
		ft_putchar_fd('\n', fd);
		return ;
	}
	while (line[i])
	{
		if (line[i] == '$')
			i += hd_expand(&line[i + 1], fd, env);
		else
			ft_putchar_fd(line[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}

int	open_heredoc(t_file *file, char *hd_name, t_env *env)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(hd_name, O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fd < 0)
		return (1);
	while (1)
	{
		line = readline(">");
		if (!line)
			exit (0);
		if (!ft_strncmp(file->file_name, line, ft_strlen(line) + 1))
			break ;
		write_to_file(file, line, fd, env);
		free(line);
	}
	free(line);
	if (close(fd))
		return (1);
	return (0);
}