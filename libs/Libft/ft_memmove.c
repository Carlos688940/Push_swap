/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:46:48 by carlaugu          #+#    #+#             */
/*   Updated: 2024/10/29 10:44:36 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*char_dest;
	unsigned const char	*char_src;

	char_dest = (unsigned char *)dest;
	char_src = (unsigned const char *)src;
	if (!dest && !src)
		return (NULL);
	if (char_dest > char_src)
	{
		while (n--)
			char_dest[n] = char_src[n];
	}
	else
	{
		while (n--)
			*char_dest++ = *char_src++;
	}
	return (dest);
}
