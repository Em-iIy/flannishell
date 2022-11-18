/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:43:36 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/17 19:29:34 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

void	*ft_calloc(unsigned int count, size_t size)
{
	unsigned int	i;
	char			*ret;

	ret = (void *)malloc(count * size);
	if (!ret)
		exit(ENOMEM);
	i = 0;
	while (i < count * size)
	{
		ret[i] = 0;
		i++;
	}
	return ((void *)ret);
}
