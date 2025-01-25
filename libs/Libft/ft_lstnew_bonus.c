/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:07:09 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/02 11:01:45 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc (sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node ->content = content;
	new_node ->next = NULL;
	return (new_node);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*name = "Carlos";
// 	t_list	*ptr;

// 	ptr = ft_lstnew(name);
// 	printf("Conteudo: %s", (unsigned char *)ptr->content);
// }