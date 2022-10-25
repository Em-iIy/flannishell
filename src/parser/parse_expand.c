/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_expand.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gwinnink <gwinnink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 16:54:32 by gwinnink      #+#    #+#                 */
/*   Updated: 2022/10/24 16:26:52 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "libft.h"

int	g_code = 0;

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
