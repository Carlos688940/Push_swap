/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:05:42 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/05 14:06:14 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlower_nbr(unsigned int n, int fd)
{
	int	i;

	i = 0;
	if (n >= 16)
		i = ft_hexlower_nbr(n / 16, fd);
	i = i + ft_char_fd("0123456789abcdef"[n % 16], fd);
	return (i);
}

int	ft_hexupper_nbr(unsigned int n, int fd)
{
	int	i;

	i = 0;
	if (n >= 16)
		i = ft_hexupper_nbr(n / 16, fd);
	i = i + ft_char_fd("0123456789ABCDEF"[n % 16], fd);
	return (i);
}
