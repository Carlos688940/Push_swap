/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:31:43 by carlaugu          #+#    #+#             */
/*   Updated: 2024/10/29 11:06:53 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	i;
	char		c;

	i = n;
	if (i < 0)
	{
		write (fd, "-", 1);
		i = -i;
	}
	if (i > 9)
		ft_putnbr_fd(i / 10, fd);
	c = (i % 10) + '0';
	write (fd, &c, 1);
}
