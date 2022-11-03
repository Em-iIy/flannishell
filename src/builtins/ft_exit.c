/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:59:52 by fpurdom           #+#    #+#             */
/*   Updated: 2022/11/02 17:15:33 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "libft.h"
#include "parser.h"

/*
*A*
if exit no args
	- print exit if 1st and last cmd
	- exit with g_code

*B*
if exit 1 valid arg
	- print exit if 1st and last cmd
	- exit with argv[1]

*C*
if argv[1] is invalid no matter how many arguments
	- print exit if 1st and last cmd
	- print `minishell: exit: argv[1] numeric argument required`
	- exit with 255

*D*
if argv[1] is valid and argv[2] exist
	- print exit if 1st and last cmd
	- print `minishell: exit: too many arguments`
	- exit with 1
	- don't exit minishell
*/
static void	exit_error_msg(char *s1, char *s2)
{
	ft_putstr_fd("minishell: exit: ", 2);
	if (s1)
		ft_putstr_fd(s1, 2);
	if (s2)
		ft_putstr_fd(s2, 2);
}

int	ft_exit(t_cmd *command)
{
	int		code;

	code = g_code;
	if (command->frst_cmd && command->lst_cmd)
		printf("exit\n");
	// *A*
	if (!command->command[1])
		exit (code);
	if (ft_check_valid_atoi(&code, command->command[1]) == false)
	{
		// *C*
		exit_error_msg(command->command[1], " numeric argument required\n");
		exit (255);
	}
	if (command->command[2])
	{
		// *D*
		exit_error_msg(NULL, "too many arguments\n");
		g_code = 1;
		return (1);
	}
	// *B*
	exit (code);
}
