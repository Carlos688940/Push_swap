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


/// este é o find_target para passar de a para b
void	find_target(t_stk_node *stk_a, t_stk_node *stk_b)
{
	t_stk_node	*b;

	if (!stk_b)
		stk_a->target = NULL;
	else
	{
		b = stk_b;
		stk_a->target = b;
		while (b)
		{
			if (b->value < stk_a->value)
			{
				if (b->value > stk_a->target->value)
					stk_a->target = b;
				else if (b->target->value < b->value)
					stk_a->target = b;
			}
			b = b->next;
		}
	}
}
/// este é o find_price para passar de a para b
void	find_price(t_stk_node *stk_a, t_stk_node *stk_b, int last_index_a, int last_index_b, t_stk_node **cheapest)
{
	int	median_a;
	int	median_b;

	median_a = last_index_a / 2;
	median_b = last_index_b / 2;
	if (stk_a->index <= median_a)
		stk_a->price = stk_a->index;
	else
		stk_a->price = (last_index_a - stk_a->index) + 1;
	if (stk_b)
	{
		if (stk_b->index <= median_b)
			stk_a->price += stk_b->index;
		else
			stk_a->price += (last_index_b - stk_b->index) + 1;
	}
	if ((*cheapest)->price > stk_a->price)
		*cheapest = stk_a;
}

void	push_to_b(t_stk_node **stk_a, t_stk_node **stk_b)
{
	int	mid_nb;
	int	last_index_a;
	int	last_index_b;
	t_stk_node	*cheapest;
	t_stk_node	*a;

	a = *stk_a;
	last_index_a = 0;
	last_index_b = 0;
	cheapest = NULL;
	last_index_a = get_last(*stk_a)->index;
	if ((*stk_b))
		last_index_b = get_last(*stk_b)->index;
	mid_nb = ft_round((get_min(*stk_a)->value + get_max(*stk_a)->value) / 2.0);
	while (last_index_a > 2)
	{
		while (a)
		{
			if (a->value <= mid_nb)
			{
				if (!cheapest)
					cheapest = a;
				find_target(a, *stk_b);
				find_price(a, *stk_b, last_index_a, last_index_b, &cheapest);
			}
			a = a->next;
		}
		while (*stk_a != cheapest)
		{
			if ((*stk_a)->index <= last_index_a / 2)
				ra(stk_a, 1);
			else
				rra(stk_a, 1);
		}
		pb(stk_a, stk_b);
		last_index_a = get_last(*stk_a)->index;
		last_index_b = get_last(*stk_b)->index;
		a = *stk_a;
	}
}

void	ft_push_swap(t_stk_node **stk_a, t_stk_node **stk_b)
{
	// t_stk_node	*cheapest;

	push_to_b(stk_a, stk_b);
	sort_three(stk_a);
}
