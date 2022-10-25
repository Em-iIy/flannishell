/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:01:02 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/14 11:05:13 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lexer_token_utils.h"
#include "lexer.h"

void	free_lexer(t_lexer **lxr)
{
	while ((*lxr)->head)
		lexer_token_del(lxr, (*lxr)->head);
	free(*lxr);
}
