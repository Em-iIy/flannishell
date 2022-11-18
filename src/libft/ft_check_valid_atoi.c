/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_valid_atoi.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 14:14:07 by gwinnink      #+#    #+#                 */
/*   Updated: 2022/11/18 14:20:19 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"

bool	ft_check_valid_atoi(int *code, char *str)
{
	int	i;

	i = 0;
	if (ft_is_longlong(str) == false)
		return (false);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (false);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i])
		return (false);
	*code = ft_atoi(str);
	return (true);
}
