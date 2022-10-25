#include "unity_fixture.h"
#include "../src/libft/libft.h"
#include "../inc/lexer.h"
#include "../inc/parser.h"
#include "../inc/environment.h"
#include "../inc/executor.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

static char	*read_file(char *file)
{
	int		fd = open(file, O_RDONLY);
	char	buffer[1];
	char	*temp, *ret;
	int		b_read = read(fd, buffer, 1);

	buffer[b_read] = 0;
	//ret = ft_strdup(buffer);
	while (b_read > 0)
	{
		temp = ret;
		ret = ft_strjoin(temp, buffer);
		b_read = read(fd, buffer, 1);
		if (b_read >= 0)
			buffer[b_read] = 0;
		free(temp);
	}
	return (ret);
}

TEST_GROUP(minishell);

TEST_SETUP(minishell)
{
}

TEST_TEAR_DOWN(minishell)
{
}

TEST(minishell, pwd)
{
	char	expected[1000], resulted[1000];
	char	*envp, *temp;
	int		fd1, fd2, b_read;
	t_lexer	*lxr;
	t_env	*env;

	temp = getenv("PATH=");
	envp = ft_strjoin("PATH=:", temp);
	env = env_cpy(&envp);
	system("pwd > expected");
	fd1 = open("expected", O_RDONLY);
	b_read = read(fd1, expected, 1000);
	expected[b_read] = 0;
	close(fd1);
	lxr = lexer("pwd > resulted");
	executor(parser(env, &lxr), &envp);
	fd2 = open("resulted", O_RDONLY);
	b_read = read(fd2, resulted, 1000);
	resulted[b_read] = 0;
	close(fd2);
	TEST_ASSERT_EQUAL_STRING(expected, resulted);
}

TEST(minishell, one_pipe)
{
	char	expected[1000], resulted[1000];
	char	*envp, *temp;
	int		fd1, fd2, b_read;
	t_lexer	*lxr;
	t_env	*env;

	temp = getenv("PATH=");
	envp = ft_strjoin("PATH=:", temp);
	env = env_cpy(&envp);
	system("pwd | wc > expected");
	fd1 = open("expected", O_RDONLY);
	b_read = read(fd1, expected, 1000);
	expected[b_read] = 0;
	close(fd1);
	lxr = lexer("pwd | wc > resulted");
	executor(parser(env, &lxr), &envp);
	fd2 = open("resulted", O_RDONLY);
	b_read = read(fd2, resulted, 1000);
	resulted[b_read] = 0;
	close(fd2);
	TEST_ASSERT_EQUAL_STRING(expected, resulted);
}