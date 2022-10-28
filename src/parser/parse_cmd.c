/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:48:40 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/27 19:14:37 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "parse_cmd_utils.h"
#include "parse_io_utils.h"
#include "parser_utils.h"
#include "parser.h"

static char	*add_cmd(char *cmds, char *new)
{
	char	*ret;
	char	*temp;

	temp = ft_strjoin(cmds, " ");
	if (!temp)
		return (NULL);
	free(cmds);
	ret = ft_strjoin(temp, new);
	if (!ret)
		return (NULL);
	free(temp);
	free(new);
	return (ret);
}

static int	check_io_iden(int iden)
{
	return (iden == GREAT || iden == GREATGREAT || \
	iden == LESS || iden == LESSLESS);
}

static char	**ft_split_n_free(char *str, char c)
{
	char	**ret;

	ret = ft_split(str, c);
	free(str);
	return (ret);
}

static void	*free_n_ret_null(void *ptr)
{
	free(ptr);
	return (NULL);
}

t_cmd	*parse_cmd(t_env *env, t_token **head)
{
	t_cmd	*ret;
	t_env	*env_temp;
	t_file	*io_temp;

	ret = cmd_new();
	env_temp = NULL;
	while (*head && (*head)->iden != PIPE)
	{
		if (check_io_iden((*head)->iden))
		{
			io_temp = parse_io(env, head);
			if (!io_temp)
				return (free_n_ret_null(env_temp));
			io_add_back(&ret->files, io_temp);
		}
		else if (check_valid_str_iden((*head)->iden, (*head)->content))
			env_add_front(&env_temp, env_new(parse_str(env, head)));
		*head = (*head)->next;
	}
	ret->command = make_envp(env_temp);
	env_free_all(&env_temp);
	return (ret);
}
