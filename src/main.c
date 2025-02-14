/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:14:13 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/12 11:22:19 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_snode	*s_a;
	t_snode	*s_b;

	s_a = NULL;
	s_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	argv = check_input(argv + 1, argc);
	stack_a_init(&s_a, argv, argc);
	if (!check_sort(s_a))
	{
		if (count_nodes(s_a) == 2 && s_a->val > s_a->nxt->val)
			sa(&s_a);
		else if (count_nodes(s_a) == 3)
			sort_three(&s_a);
		else
			ft_push_swap(&s_a, &s_b);
	}
	free_stack(s_a, argv, argc, 0);
	return (0);
}
