/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_msg.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 19:17:41 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/16 13:55:03 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	display_error(char *name, char *msg1, char *msg2, char *msg3)
{
	ft_putstr_fd("minishell: ", 2);
	if (name)
	{
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": ", 2);
	}
	if (msg1)
		ft_putstr_fd(msg1, 2);
	if (msg2)
		ft_putstr_fd(msg2, 2);
	if (msg3)
		ft_putstr_fd(msg3, 2);
	ft_putchar_fd('\n', 2);
	return (1);
}
