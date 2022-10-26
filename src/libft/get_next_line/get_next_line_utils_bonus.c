/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 15:12:24 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/04/15 16:51:24 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	nl_position(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

static size_t	s_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*make_save(char *save, char *buffer)
{
	char	*new_save;
	int		i;

	new_save = (char *)malloc(sizeof(char) * (s_len(save) + s_len(buffer) + 1));
	if (!new_save)
		return (NULL);
	i = 0;
	while (save[i])
	{
		new_save[i] = save[i];
		i++;
	}
	free(save);
	while (*buffer)
	{
		new_save[i] = *buffer;
		i++;
		buffer++;
	}
	new_save[i] = '\0';
	return (new_save);
}

char	*make_line(char *static_save)
{
	char	*line;
	int		split_pos;

	if (!static_save)
		return (NULL);
	split_pos = nl_position(static_save);
	if (split_pos == 0)
		split_pos = s_len(static_save);
	line = (char *)malloc(sizeof(char) * (split_pos + 1));
	if (!line)
		return (NULL);
	line[split_pos] = '\0';
	split_pos--;
	while (split_pos >= 0)
	{
		line[split_pos] = static_save[split_pos];
		split_pos--;
	}
	return (line);
}

char	*to_next_line(char *old_save)
{
	char	*new_save;
	int		i;
	int		k;

	if (!old_save)
		return (NULL);
	k = 0;
	while (old_save[k] && old_save[k] != '\n')
		k++;
	if (old_save[k] == '\n')
		k++;
	new_save = (char *)malloc(sizeof(char) * (s_len(&old_save[k]) + 1));
	if (!new_save)
		return (NULL);
	i = 0;
	while (old_save[k])
	{
		new_save[i] = old_save[k];
		i++;
		k++;
	}
	new_save[i] = '\0';
	free(old_save);
	return (new_save);
}
