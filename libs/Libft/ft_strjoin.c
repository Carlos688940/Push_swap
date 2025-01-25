/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:13:39 by carlaugu          #+#    #+#             */
/*   Updated: 2024/10/29 11:14:15 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	big_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	big_len = ft_strlen(s1) + ft_strlen(s2);
	new = malloc ((big_len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	ft_memcpy(&new[i], s2, ft_strlen(s2) + 1);
	return (new);
}
