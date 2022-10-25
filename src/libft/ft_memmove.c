/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:44:02 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/22 18:04:04 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char			*dstbuff;
	const char		*srcbuff;
	unsigned int	i;

	dstbuff = dst;
	srcbuff = src;
	i = 0;
	if (!dst || !src)
		return (NULL);
	if (dst > src)
	{
		while (n--)
			dstbuff[n] = srcbuff[n];
	}
	else
	{
		while (i < n)
		{
			dstbuff[i] = srcbuff[i];
			i++;
		}
	}
	return (dst);
}
