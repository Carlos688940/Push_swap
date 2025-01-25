/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:20:32 by carlaugu          #+#    #+#             */
/*   Updated: 2024/10/29 11:17:39 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!lit[0])
		return ((char *)big);
	while (i < n && big[i])
	{
		if (big[i] == lit[0])
		{
			j = 0;
			while ((lit[j]) && (lit[j] == big[i + j]) && (i + j < n))
				j++;
			if (!lit[j])
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
