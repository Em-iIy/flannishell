/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hd_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 19:03:57 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/11 15:52:59 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "signals.h"
#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <fcntl.h>
#include <unistd.h>

char	*create_hd_file(t_file *files)
{
	static int	i = 0;
	char		*file_n;
	char		*hd_name;
	char		*delimiter;

	file_n = ft_itoa(i);
	hd_name = ft_strjoin(".hd_file_", file_n);
	free(file_n);
	delimiter = files->file_name;
	files->file_name = hd_name;
	i++;
	return (delimiter);
}

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
	fd = open(file->file_name, O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fd < 0)
		return (1);
	signal(SIGINT, sig_func_heredoc);
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (!ft_strncmp(hd_name, line, ft_strlen(line) + 1))
			break ;
		write_to_file(file, line, fd, env);
		free(line);
	}
	free(line);
	free(hd_name);
	if (close(fd))
		return (1);
	return (0);
}
