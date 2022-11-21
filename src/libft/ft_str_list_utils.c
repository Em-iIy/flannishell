/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:50:43 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/21 13:16:12 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"

t_str_list	*ft_str_list_new(char *str)
{
	t_str_list	*ret;

	if (!str)
		return (NULL);
	ret = (t_str_list *)malloc(sizeof(t_str_list));
	if (!ret)
		exit (ENOMEM);
	ret->next = NULL;
	ret->str = ft_strdup(str);
	return (ret);
}

void	ft_str_list_add_front(t_str_list **list, t_str_list *new)
{
	new->next = *list;
	*list = new;
}

void	ft_str_list_free(t_str_list *list)
{
	free(list->str);
	free(list);
}

void	ft_str_list_free_all(t_str_list **head)
{
	t_str_list	*temp;

	while (*head)
	{
		temp = (*head)->next;
		ft_str_list_free(*head);
		*head = temp;
	}
}
