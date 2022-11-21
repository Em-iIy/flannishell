/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:03:55 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/21 13:24:34 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"

t_str_list	*ft_str_arr_to_list(char **arr)
{
	t_str_list	*ret;

	ret = NULL;
	while (*arr)
	{
		ft_str_list_add_front(&ret, ft_str_list_new(*arr));
		arr++;
	}
	return (ret);
}

char	**ft_str_list_to_arr(t_str_list *list)
{
	char		**ret;
	t_str_list	*temp;
	int			i;

	i = 0;
	temp = list;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	ret = (char **)malloc((i + 1) * sizeof(char *));
	if (!ret)
		exit(ENOMEM);
	ret[i] = NULL;
	i--;
	temp = list;
	while (i >= 0)
	{
		ret[i] = ft_strdup(temp->str);
		temp = temp->next;
		i--;
	}
	return (ret);
}
