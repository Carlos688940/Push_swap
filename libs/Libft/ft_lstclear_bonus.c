/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:16:40 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/02 11:01:31 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*box;

	ptr = *lst;
	while (ptr != NULL)
	{
		box = ptr;
		del(ptr->content);
		ptr = ptr->next;
		free(box);
	}
	*lst = NULL;
}

// void	ft_delete(void *ptr);

// void	ft_delete(void *ptr)
// {
// 	free(ptr);
// }

// #include <stdio.h>
// int	main(void)
// {
// 	t_list	*list;
// 	t_list	*new_node;
// 	char	*name = "Carlos";
// 	char	*name1 = "Ana";

// 	list = NULL;
// 	new_node = malloc (sizeof(t_list));
// 	new_node->content = ft_strdup(name);
// 	new_node->next = NULL;
// 	list = new_node;
// 	new_node = malloc (sizeof(t_list));
// 	new_node->content = ft_strdup(name1);
// 	new_node->next = NULL;
// 	list->next = new_node;	
// 	ft_lstclear(&list, ft_delete);
// }