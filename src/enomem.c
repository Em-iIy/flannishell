/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enomem.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 16:41:41 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/18 13:48:54 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "heredoc.h"

int	check_memory(int *status, t_cmd *cmds)
{
	if (WEXITSTATUS(*status) == ENOMEM)
	{
		rm_heredoc_files(cmds);
		exit (ENOMEM);
	}
	return (WEXITSTATUS(*status));
}
