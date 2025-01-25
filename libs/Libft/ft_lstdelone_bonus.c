/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:16:46 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/02 11:01:34 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void	ft_delete(void *ptr)
// {
// 	free(ptr);
// }

// void	ft_delete(void *ptr);

// #include <stdio.h>
// int	main(void)
// {
// 	t_list	*list;
// 	char	*name = "Carlos";

// 	list = NULL;
// 	list = malloc(sizeof(t_list));
// 	list->content = ft_strdup(name);
// 	list->next = NULL;
// 	ft_lstdelone(list, ft_delete);
// }