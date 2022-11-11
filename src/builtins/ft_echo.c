/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_echo.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 14:08:02 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/11 17:55:37 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <unistd.h>
#include <stdbool.h>

static bool	check_noption(char ***strs)
{
	bool	n_option;
	int		i;

	i = 0;
	n_option = false;
	while (**strs && (**strs)[i] == '-')
	{
		i++;
		if ((**strs)[i] != 'n')
			return (n_option);
		while ((**strs)[i] == 'n' && (**strs)[i])
			i++;
		if (!(**strs)[i])
			n_option = true;
		else
			return (false);
		(*strs)++;
		i = 0;
	}
	return (n_option);
}

int	ft_echo(char **strs)
{
	bool	n_option;

	n_option = check_noption(&strs);
	while (*strs)
	{
		ft_putstr_fd(*strs, 1);
		if (*(strs + 1) && **strs)
			ft_putchar_fd(' ', 1);
		strs++;
	}
	if (n_option == false)
		ft_putchar_fd('\n', 1);
	g_code = 0;
	return (1);
}
