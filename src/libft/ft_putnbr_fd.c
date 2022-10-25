/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:44:14 by gwinnink          #+#    #+#             */
/*   Updated: 2022/02/22 18:11:06 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int		out;
	long	tmp;

	tmp = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		tmp *= -1;
	}
	out = tmp % 10 + '0';
	tmp /= 10;
	if (tmp > 0)
		ft_putnbr_fd((int)tmp, fd);
	write(fd, &out, 1);
	return ;
}
