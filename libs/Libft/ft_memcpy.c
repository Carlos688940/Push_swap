/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:35:38 by carlaugu          #+#    #+#             */
/*   Updated: 2024/10/29 11:04:41 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*char_dest;
	unsigned const char	*char_src;

	char_dest = (unsigned char *)dest;
	char_src = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (n--)
		*char_dest++ = *char_src++;
	return (dest);
}
