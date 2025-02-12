/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:06:28 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/05 14:06:29 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(long long n, int fd)
{
	int	i;

	i = 0;
	if (n > 9)
		i = ft_putnbr(n / 10, fd);
	i = i + ft_char_fd("0123456789"[n % 10], fd);
	return (i);
}

int	ft_number(int n, int fd)
{
	int			i;
	long long	num;

	i = 0;
	num = n;
	if (num < 0)
	{
		i = write (fd, "-", 1);
		num = -num;
	}
	i += ft_putnbr(num, fd);
	return (i);
}
