/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:57:05 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/04 23:13:27 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putpointer(unsigned long long n, int fd)
{
	int	i;

	i = 0;
	if (n >= 16)
		i = ft_putpointer(n / 16, fd);
	i = i + ft_char_fd("0123456789abcdef"[n % 16], fd);
	return (i);
}

int	ft_pointer(unsigned long long n, int fd)
{
	int	i;

	if (n == 0)
		return (ft_str_fd("(nil)", fd));
	else
	{
		i = ft_str_fd("0x", fd);
		i += ft_putpointer(n, fd);
	}
	return (i);
}
