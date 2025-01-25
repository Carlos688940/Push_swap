/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:16:34 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/02 11:01:24 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ptr = *lst;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = new;
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_list	part1;
// 	t_list	part2;
// 	t_list	part3;
// 	t_list	*ptr;
// 	char	*name = "Carlos";
// 	char	*name1 = "Ana";
// 	char	*name2 = "Joao";

// 	part1.content = name;
// 	part1.next = &part2;
// 	part2.content = name1;
// 	part2.next = NULL;
// 	part3.content = name2;
// 	part3.next = NULL;
// 	ptr = &part1;
// 	ft_lstadd_back(&ptr, &part3);
// 	while (ptr != NULL)
// 	{
// 		printf("Content:%s\n", (char *)ptr->content);
// 		printf("Address:%p\n\n", (char *)ptr->next);
// 		ptr = ptr->next;
// 	}
// }