/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:14:39 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/10 11:19:04 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*ret;

	if (!s1 | !s2)
		return (NULL);
	ret = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (ret);
}
