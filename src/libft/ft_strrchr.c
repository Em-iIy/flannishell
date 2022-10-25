/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:44:49 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/23 10:09:50 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		ret_index;
	int		i;

	i = 0;
	ret_index = -1;
	while (str[i])
	{
		if (str[i] == (char)c)
			ret_index = i;
		i++;
	}
	if (!str[i] && c == 0)
		return ((char *)&str[i]);
	if (ret_index == -1)
		return (NULL);
	return ((char *)&str[ret_index]);
}
