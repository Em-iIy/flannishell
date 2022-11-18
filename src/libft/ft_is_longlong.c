/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_is_longlong.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 14:08:23 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/11/18 14:32:29 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

#include <stdio.h>

bool	ft_is_longlong(char *str)
{
	int		i;
	bool	neg;

	i = 0;
	neg = false;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		neg = true;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (ft_strlen(&str[i]) < 19)
		return (true);
	if (ft_strlen(&str[i]) > 19)
		return (false);
	if (neg == true && (ft_strncmp(&str[i], "9223372036854775808", 19) > 0))
		return (false);
	else if (neg == false && ft_strncmp(&str[i], "9223372036854775807", 19) > 0)
		return (false);
	return (true);
}
