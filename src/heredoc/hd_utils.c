/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hd_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 19:03:57 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/18 15:16:47 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <fcntl.h>
#include <unistd.h>
#include "parser.h"
#include "libft.h"
#include "signals.h"

char	*create_hd_file(t_file *files)
{
	char		*file_n;
	char		*hd_name;
	char		*delimiter;

	file_n = ft_itoa(files->i);
	hd_name = ft_strjoin(".hd_file_", file_n);
	free(file_n);
	delimiter = files->file_name;
	files->file_name = hd_name;
	return (delimiter);
}

static int	hd_expand(char *line, int fd, t_env *env)
{
	int		i;
	char	*key;
	char	*env_var;

	i = 0;
	while (line[i] && (ft_isalnum(line[i]) || line[i] == '_'))
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

	i = 0;
	if (file->hd_quotes)
	{
		ft_putstr_fd(line, fd);
		ft_putchar_fd('\n', fd);
		return ;
	}
	while (line[i])
	{
		if (line[i] == '$' && (ft_isalnum(line[i + 1]) || line[i + 1] == '_'))
			i += hd_expand(&line[i + 1], fd, env);
		else
			ft_putchar_fd(line[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}

int	open_heredoc(t_file *file, char *delimiter, t_env *env)
{
	int		fd;
	char	*line;

	fd = open(file->file_name, O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fd < 0)
		return (3);
	signal(SIGINT, SIG_DFL);
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (!ft_strncmp(delimiter, line, ft_strlen(line) + 1))
			break ;
		write_to_file(file, line, fd, env);
		free(line);
	}
	if (close(fd))
		return (3);
	return (0);
}
