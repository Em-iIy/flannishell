/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:39:44 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/15 17:25:44 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern int	g_code;

int	ft_pwd(void)
{
	char	*temp;

	temp = getcwd(NULL, 0);
	if (!temp)
		exit (1);
	printf("%s\n", temp);
	free(temp);
	g_code = 0;
	return (1);
}
