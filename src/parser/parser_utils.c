/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:34:14 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/17 19:31:23 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include <errno.h>

t_parser	*init_parser(void)
{
	t_parser	*ret;

	ret = (t_parser *)malloc(sizeof(t_parser));
	if (!ret)
		exit(ENOMEM);
	ret->cmds = NULL;
	ret->count = 0;
	return (ret);
}
