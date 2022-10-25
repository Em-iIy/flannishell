/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:28:47 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/18 20:48:26 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "lexer.h"

void	lexer_token_print(t_token *token)
{
	t_token	*temp;
	int		i;

	i = 0;
	if (!token)
		return ;
	temp = token;
	printf("Tokens:\n--------------------------------------------------------------\nContent:\t");
	while (temp)
	{
		printf("`%s` | ", temp->content);
		temp = temp->next;
	}
	printf("\n");
	temp = token;
	printf("str_end:\t");
	while (temp)
	{
		printf("`%d`", temp->str_end);
		i = ft_strlen(temp->content) - 1;
		while (i > 0)
		{
			printf(" ");
			i--;
		}
		printf(" | ");
		temp = temp->next;
	}
	printf("\n");
	temp = token;
	printf("iden:\t\t");
	while (temp)
	{
		printf("`%d`", temp->iden);
		i = ft_strlen(temp->content) - 1;
		while (i > 0)
		{
			printf(" ");
			i--;
		}
		printf(" | ");
		temp = temp->next;
	}
	printf("\n");
	temp = token;
	printf("start:\t\t");
	while (temp)
	{
		printf("`%d`", temp->start_pos);
		i = ft_strlen(temp->content) - 1;
		while (i > 0)
		{
			printf(" ");
			i--;
		}
		printf(" | ");
		temp = temp->next;
	}
	printf("\n");
	temp = token;
	printf("end:\t\t");
	while (temp)
	{
		printf("`%d`", temp->end_pos);
		i = ft_strlen(temp->content) - 1;
		while (i > 0)
		{
			printf(" ");
			i--;
		}
		printf(" | ");
		temp = temp->next;
	}
	printf("\n");
}
