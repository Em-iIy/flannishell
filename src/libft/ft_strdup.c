/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:44:25 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/03 15:34:36 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		str_size;

	str_size = ft_strlen(s1);
	ret = (char *)malloc(str_size + 1);
	if (!ret)
		exit(-1);
	ret[str_size] = (char) s1[str_size];
	while (str_size--)
		ret[str_size] = (char) s1[str_size];
	return (ret);
}
