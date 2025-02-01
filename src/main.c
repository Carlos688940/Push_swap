/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-25 12:14:13 by carlaugu          #+#    #+#             */
/*   Updated: 2025-01-25 12:14:13 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include <stdio.h>

int abc = 0;

int	main(int argc, char **argv)
{
	t_stk_node	*stk_a;
	t_stk_node	*stk_b;

	stk_a = NULL;
	stk_b = NULL;
	(void)stk_b;
	if (argc == 1 || !argv[1][0])
		return (1);
	argv = check_input(argv + 1, argc);
	stack_a_init(&stk_a, argv, argc);
	if (!check_sort(stk_a))
	{
		if (count_nodes(stk_a) == 2 && stk_a->value > stk_a->next->value)
			sa(&stk_a, 1);
		else if (count_nodes(stk_a) == 3)
			sort_three(&stk_a);
		else
			ft_push_swap(&stk_a, &stk_b);
	}
	printf("\n\n\n%d\n", abc);
	stk_b = stk_a;
	while (stk_b)
	{
		printf("index: %d, value:%d\n", stk_b->index, stk_b->value);
		stk_b = stk_b->next;
	}	
	free_stack(stk_a, argv, argc, 0);
	return (0);
}
