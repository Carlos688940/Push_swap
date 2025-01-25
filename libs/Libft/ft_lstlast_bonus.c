/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:22:53 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/02 11:01:40 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	while (ptr != NULL)
	{
		if (ptr->next == NULL)
			return (ptr);
		ptr = ptr->next;
	}
	return (ptr);
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_list	part1;
// 	t_list	part2;
// 	t_list	part3;
// 	t_list	*result;
// 	char	*name = "Carlos";
// 	char	*name1 = "Ana";
// 	char	*name2 = "Joao";

// 	part1.content = name;
// 	part1.next = &part2;
// 	part2.content = name1;
// 	part2.next = &part3;
// 	part3.content = name2;
// 	part3.next = NULL;
// 	result = ft_lstlast(&part1);

// 	printf("Result: %s",(char *)result->content);
// }