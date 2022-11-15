/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:16:04 by fpurdom           #+#    #+#             */
/*   Updated: 2022/11/15 14:31:30 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <signal.h>
#include "libft.h"
#include "parser.h"
#include "heredoc.h"

extern int	g_code;


/*
Set terminal settings to default
fixes SIGQUIT out of programs that change terminal settings (top)
*/
void	suppress_sig_output(void)
{
	struct termios	new_settings;

	if (tcgetattr(0, &new_settings))
		perror("minishell: tcsetattr");
	// new_settings.c_lflag &= ~ECHOCTL;
	new_settings.c_iflag = 0x6b02;
	new_settings.c_oflag = 0x3;
	new_settings.c_cflag = 0x4b00;
	new_settings.c_lflag = 0x200005cf;
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

int	sig_func_heredoc(int sig, t_cmd *cmds)
{
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		g_code = 1;
		if (rm_heredoc_files(cmds))
			return (3);
		return (1);
	}
	return (0);
}
