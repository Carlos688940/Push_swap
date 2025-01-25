/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:48:58 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/02 11:00:19 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *list, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*box;

	if (!list || !f || !del)
		return (NULL);
	new_list = ft_lstnew(f(list->content));
	if (!new_list)
		return (NULL);
	box = new_list;
	list = list->next;
	while (list)
	{
		box->next = ft_lstnew(f(list->content));
		if (!box->next)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		box = box->next;
		list = list->next;
	}
	return (new_list);
}

// void	*ft_change(void *str)
// {
// 	char	*s;
// 	int	i;

// 	i = 0;
// 	s = strdup(str);
// 	if (!s)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		s[i] = ft_toupper(s[i]);
// 		i++;
// 	}
// 	return (s);
// }

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
// 	t_list	*result;
// 	t_list	*box;
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
// 	result = ft_lstmap(list, ft_change, ft_delete);
// 	box = NULL;
// 	printf("Original :%s\n",(char *)list->content);
// 	printf("Nova :%s",(char *)result->content);
// 	while (list)
// 	{	
// 		box = list;
// 		free (list->content);
// 		list = list->next;
// 		free(box);

// 	}
// 	while (result)
// 	{	
// 		box = result;
// 		free (result->content);
// 		result = result->next;
// 		free(box );

// 	}
// }