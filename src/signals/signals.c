/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 14:16:04 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/11 14:35:29 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <signal.h>
#include "libft.h"

extern int	g_code;

void	suppress_sig_output(void)
{
	struct termios	new_settings;

	if (tcgetattr(0, &new_settings))
		perror("minishell: tcsetattr");
	new_settings.c_lflag &= ~ECHOCTL;
	if (tcsetattr(0, 0, &new_settings))
		perror("minishell: tcsetattr");
}

void	unsuppress_sig_output(void)
{
	struct termios	new_settings;

	if (tcgetattr(0, &new_settings))
		perror("minishell: tcsetattr");
	new_settings.c_lflag |= ECHOCTL;
	if (tcsetattr(0, 0, &new_settings))
		perror("minishell: tcsetattr");
}

void	sig_func_parent(int sig)
{
	if (sig == 2)
	{
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_code = 1;
	}
}

int	sig_func_child(int sig)
{
	if (sig == SIGINT)
		ft_putchar_fd('\n', 1);
	else if (sig == SIGQUIT)
		ft_putstr_fd("Quit: 3\n", 1);
	return (128 + sig);
}

void	sig_func_heredoc(int sig)
{
	if (sig == 2)
	{
		ft_putchar_fd('\n', 1);
		g_code = 1;
		exit (1);
	}
}
