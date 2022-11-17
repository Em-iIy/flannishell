/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:48:40 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/17 14:04:23 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "parse_cmd_utils.h"
#include "parse_io_utils.h"
#include "parser_utils.h"
#include "parser.h"
#include "environment.h"

static int	check_io_iden(int iden)
{
	return (iden == GREAT || iden == GREATGREAT || \
	iden == LESS || iden == LESSLESS);
}

static void	env_add_n_free(t_env *env, t_token **head, t_env **env_temp)
{
	char	*temp;

	temp = parse_str(env, head);
	env_add_front(env_temp, env_new(temp));
	free(temp);
}

t_cmd	*parse_cmd(t_env *env, t_token **head)
{
	t_cmd	*ret;
	t_env	*env_temp;
	t_file	*io_temp;
	int		i;

	i = 0;
	ret = cmd_new();
	env_temp = NULL;
	while (*head && (*head)->iden != PIPE)
	{
		if (check_io_iden((*head)->iden))
		{
			io_temp = parse_io(env, head, i);
			if (!io_temp)
				return (env_free_all(&env_temp), cmd_free(ret), NULL);
			io_add_back(&ret->files, io_temp);
			i++;
		}
		else if (check_valid_str_iden((*head)->iden, (*head)->content))
			env_add_n_free(env, head, &env_temp);
		*head = (*head)->next;
	}
	ret->command = make_envp(env_temp);
	env_free_all(&env_temp);
	return (ret);
}
