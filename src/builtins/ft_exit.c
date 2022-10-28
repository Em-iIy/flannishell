/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_exit.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 14:59:52 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/10/28 15:14:12 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "parser.h"

int	ft_exit(t_cmd *command)
{
	if (command->frst_cmd && command->lst_cmd)
		printf("exit\n");
	exit (0);
}
