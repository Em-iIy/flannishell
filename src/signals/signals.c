/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:16:04 by fpurdom           #+#    #+#             */
/*   Updated: 2022/11/15 16:09:02 by gwinnink         ###   ########.fr       */
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
	// new_settings.c_lflag &= ~ECHOCTL;
*/
/* Setting definitions in termios.h
These are the default settings bash starts off with!
c_iflag:
	- BRKINT          0x00000002      map BREAK to SIGINTR
	- ICRNL           0x00000100      map CR to NL (ala CRMOD)
	- IXON            0x00000200      enable output flow control
	- IXANY           0x00000800      any char will restart after stop
	- IMAXBEL         0x00002000      ring bell on input queue full
	- IUTF8           0x00004000      maintain state for UTF-8 VERASE
			total:	 <0x00006b02>

c_oflag:
	- OPOST           0x00000001      enable following output processing
	- ONLCR           0x00000002      map NL to CR-NL (ala CRMOD)
			total:	 <0x00000003>

c_cflag:
	- CSIZE           0x00000300      character size mask
		- CS8             0x00000300      8 bits
	- CREAD           0x00000800      enable receiver
	- HUPCL           0x00004000      hang up on last close
			total:	 <0x00004b00>

c_lflag:
	- ECHOKE          0x00000001      visual erase for line kill
	- ECHOE           0x00000002      visually erase chars
	- ECHOK           0x00000004      echo NL after line kill
	- ECHO            0x00000008      enable echoing
	- ISIG            0x00000080      enable signals INTR, QUIT, [D]SUSP
	- ICANON          0x00000100      canonicalize input lines
	- IEXTEN          0x00000400      enable DISCARD and LNEXT
	- PENDIN          0x20000000      XXX retype pending input (state)
			total:	 <0x2000058f>

*/
void	suppress_sig_output(void)
{
	struct termios	new_settings;

	if (tcgetattr(0, &new_settings))
		perror("minishell: tcsetattr");
	new_settings.c_iflag = 0x6b02;
	new_settings.c_oflag = 0x3;
	new_settings.c_cflag = 0x4b00;
	new_settings.c_lflag = 0x2000058f;
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
