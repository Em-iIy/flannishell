/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:54:32 by gwinnink          #+#    #+#             */
/*   Updated: 2022/10/27 16:30:44 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "libft.h"

char	*parser_expand(t_env *env, char *str)
{
	char	*ret;
	char	*temp;
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	temp = ft_substr(str, 0, i);
	if (!ft_strncmp(temp, "?", 2))
	{
		free(temp);
		return (ft_itoa(g_code));
	}
	ret = ft_strjoin(get_env(env, temp), &str[i]);
	if (!ret)
		ret = ft_strdup(&str[i]);
	free(temp);
	return (ret);
}
