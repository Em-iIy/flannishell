/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:54:32 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/18 11:42:03 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "libft.h"

static char	*parser_expand_g_code(char *str)
{
	char	*ret;
	char	*temp;

	if (str && str[0] == '?')
	{
		temp = ft_itoa(g_code);
		ret = ft_strjoin(temp, &str[1]);
		free(temp);
		return (ret);
	}
	return (NULL);
}

char	*parser_expand(t_env *env, char *str)
{
	char	*ret;
	char	*temp;
	int		i;

	i = 0;
	temp = parser_expand_g_code(str);
	if (temp)
		return (temp);
	while (str[i] && (str[i] == '_' || ft_isalnum(str[i])))
		i++;
	if (!i)
		return (ft_strjoin("$", str));
	temp = ft_substr(str, 0, i);
	ret = ft_strjoin(get_env(env, temp), &str[i]);
	if (!ret)
		ret = ft_strdup(&str[i]);
	free(temp);
	return (ret);
}
