/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enomem.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 16:41:41 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/14 14:41:24 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>

int	check_memory(int *status)
{
	if (WEXITSTATUS(*status) == ENOMEM)
		exit (ENOMEM);
	return (WEXITSTATUS(*status));
}