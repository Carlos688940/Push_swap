/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:56:40 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/04 22:11:40 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_nbr(unsigned int n, int fd)
{
	int	i;

	i = 0;
	if (n > 9)
		i = ft_unsigned_nbr(n / 10, fd);
	i = i + ft_char_fd("0123456789"[n % 10], fd);
	return (i);
}
