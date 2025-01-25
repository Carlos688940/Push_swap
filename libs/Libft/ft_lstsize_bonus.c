/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:07:17 by carlaugu          #+#    #+#             */
/*   Updated: 2024/11/02 11:01:48 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int		count;

	ptr = lst;
	count = 0;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_list	part1;
// 	t_list	part2;
// 	t_list	part3;
// 	char	*name = "Carlos";
// 	char	*name1 = "Ana";
// 	char	*name2 = "Joao";

// 	part1.content = name;
// 	part1.next = NULL;
// 	part2.content = name1;
// 	part2.next = &part1;
// 	part3.content = name2;
// 	part3.next = &part2;

// 	printf("Result: %d",ft_lstsize(&part3));
// }