/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:44:54 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/17 19:30:52 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <errno.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	i = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		exit(ENOMEM);
	while (i < len && s[start + i])
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
