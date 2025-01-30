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
	stk_a = stack_a_init(stk_a, argv, argc);
	if (!check_sort(stk_a))
	{
		if (count_nodes(stk_a) == 2)
			stk_a = sa(stk_a);
		else if (count_nodes(stk_a) == 3)
			stk_a = sort_three(stk_a);
		else
			ft_push_swap(stk_a, stk_b);
	}
	free_stack(stk_a, argv, argc, 0);
	return (0);
}
