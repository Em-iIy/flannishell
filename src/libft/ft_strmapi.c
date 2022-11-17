/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:44:41 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/17 19:30:43 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

char	*ft_strmapi(const char	*s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ret;

	i = 0;
	if (!s)
		return (0);
	ret = (char *)malloc(ft_strlen(s) + 1);
	if (!ret)
		exit(ENOMEM);
	while (s[i])
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
