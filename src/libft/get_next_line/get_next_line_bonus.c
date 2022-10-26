/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 15:12:04 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/10/26 18:32:34 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

char	*check_error(char *static_save, int b_read)
{
	if (static_save && (!*static_save || b_read < 0))
	{
		free(static_save);
		static_save = NULL;
	}
	return (static_save);
}

char	*get_next_line(int fd)
{
	static char	*static_save[1024];
	char		buffer[2];
	char		*line;
	int			b_read;

	if (fd < 0 || fd > 1024)
		return (NULL);
	b_read = 1;
	if (!static_save[fd])
	{
		static_save[fd] = (char *)malloc(sizeof(char));
		if (!static_save[fd])
			return (NULL);
		*static_save[fd] = '\0';
	}
	while (!nl_position(static_save[fd]) && b_read > 0)
	{
		b_read = read(fd, buffer, 1);
		buffer[b_read] = '\0';
		static_save[fd] = make_save(static_save[fd], buffer);
	}
	static_save[fd] = check_error(static_save[fd], b_read);
	line = make_line(static_save[fd]);
	static_save[fd] = to_next_line(static_save[fd]);
	return (line);
}
