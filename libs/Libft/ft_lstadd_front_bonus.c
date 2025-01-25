/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:07:05 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/02 11:01:28 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_list	*ptr;
// 	char	*name = "Carlos";
// 	char	*name2 = "Joao";
// 	t_list	struct1;
// 	t_list	struct2;
// 	(void)struct2;

// 	struct1.content = name;
// 	struct1.next = NULL;
// 	ptr = &struct1;
// 	struct2.content = name2;
// 	struct2.next = NULL;
// 	printf("Ptr Content before: %s\n", (char *)ptr->content);
// 	printf("Ptr next before: %p\n\n", (char *)ptr->next);
// 	ft_lstadd_front(&ptr, NULL);
// 	printf("Ptr Content after: %s\n", (char *)ptr->content);
// 	printf("Ptr next after: %p\n", (char *)ptr->next);

// }