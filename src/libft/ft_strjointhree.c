/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjointhree.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 14:48:07 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/10/26 16:42:34 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

char	*ft_strjointhree(const char *s1, const char *s2, const char *s3)
{
	char	*ret;
	char	*temp;

	temp = ft_strjoin(s1, s2);
	if (!temp)
		exit (ENOMEM);
	ret = ft_strjoin(temp, s3);
	free(temp);
	if (!ret)
		exit (ENOMEM);
	return (ret);
}
