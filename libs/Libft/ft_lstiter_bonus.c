/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:43:13 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/02 11:01:37 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;

	if (!lst || !f)
		return ;
	ptr = lst;
	while (ptr)
	{
		f(ptr->content);
		ptr = ptr->next;
	}
}

// #include <stdio.h>
// void	ft_change(void *ptr)
// {
// 	char	*str;

// 	str = (char *)ptr;
// 	while (*str)
// 	{
// 		*str = ft_toupper(*str);
// 		str++;
// 	}
// }

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
// 	printf("Antes da função: %s\n", (char *)list->content);
// 	printf("Antes da função: %s\n\n\n", (char *)new_node->content);
// 	ft_lstiter(list, ft_change);
// 	printf("Depois da função: %s\n", (char *)list->content);
// 	printf("Depois da função: %s\n", (char *)new_node->content);
// }