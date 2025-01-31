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

int	ft_round(float i)
{
	int	j;

	j = i + 0.5;
	return (j);
}

	// // int	median;
	// int	middle_point;
	// int	stk_len;
	// int	half_len;
	// int	min;

	// // (void)median;
	// (void)middle_point;
	// (void)stk_len;
	// (void)min;
	// (void)stk_b;
	// stk_len = get_last(*stk_a)->index + 1;
	// // median = ft_round(stk_len / 2.0) - 1;
	// half_len = ft_round(stk_len / 2.0) - 1;

	// while (*stk_a && get_last(*stk_a)->index > half_len)
	// {
	// 	min = get_min(*stk_a)->value;

	// 	*stk_a = (*stk_a)->next; 
	// }


void	pb(t_stk_node **stk_a, t_stk_node **stk_b)
{
	t_stk_node	*box;

	box = *stk_a;
	*stk_a = (*stk_a)->next;
	(*stk_a)->previous = NULL;
	box->next = *stk_b;
	if (*stk_b)
		(*stk_b)->previous = box;
	box->previous = NULL;
	*stk_b = box;
	define_index(*stk_a);
	define_index(*stk_b);
	ft_putstr_fd("pb\n", 1);
}

void	ft_push_swap(t_stk_node **stk_a, t_stk_node **stk_b)
{
	int	median;
	int	stk_len;
	int	mid_len;
	int	max_ind_actual;
	t_stk_node	*min;
	(void)min;

	stk_len = get_last(*stk_a)->index + 1;
	mid_len = stk_len / 2;
	median = mid_len;
	max_ind_actual = stk_len - 1;
	while (*stk_a)
	{
		while (max_ind_actual >= mid_len)
		{
			min = get_min(*stk_a);
			while ((*stk_a)->value != min->value)
			{
				if ((*stk_a)->index <= median)
					ra(stk_a);
				else
					rra(stk_a);
			}
			pb(stk_a, stk_b);
			max_ind_actual = get_last(*stk_a)->index;
			median = max_ind_actual / 2;
		}
		break;
	}
}