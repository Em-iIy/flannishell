/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_prsr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:01:44 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/18 19:02:55 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parse_cmd_utils.h"

void	free_parser(t_parser *prsr)
{
	cmd_free_all(prsr->cmds);
	free(prsr);
}
