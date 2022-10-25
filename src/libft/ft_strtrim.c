/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:44:52 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/22 17:58:44 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int		ret_len;

	while (ft_strchr((char *)set, *s1) && *s1)
		s1++;
	ret_len = ft_strlen(s1);
	while (ret_len && ft_strchr((char *)set, s1[ret_len]))
		ret_len--;
	return (ft_substr(s1, 0, ret_len + 1));
}
