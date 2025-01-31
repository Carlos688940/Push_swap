/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-30 21:09:27 by carlaugu          #+#    #+#             */
/*   Updated: 2025-01-30 21:09:27 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push_swap(t_stk_node **stk_a, t_stk_node **stk_b)
{
	int	median;
	int	middle_point;
	t_stk_node	*last;

	(void)stk_b;
	(void)median;
	(void)middle_point;
	define_index(*stk_a);
	// last = get_last(*stk_a);
	last = get_last(*stk_a);
	median = (last->index + 1) / 2;
	// middle_point = (get_min(*stk_a) + get_max(*stk_a)) / 4;
	// while (*stk_a)
	// {
	// 	if (get_last(*stk_a)->index == 2)
	// 		break;
	// 	// if (stk_a->value < middle_point)
	// 		// 
	// }
}