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

void	push_to_b(t_stk_node **stk_a, t_stk_node **stk_b)
{
	int	mid_nb;
	int	median;
	int	last_index;

	(void)median;
	last_index = get_last(*stk_a)->index;
	while (last_index > 2)
	{
		median = last_index / 2;
		mid_nb = ft_round((get_max(*stk_a)->value + get_min(*stk_a)->value) / 2.0);
		if ((*stk_a)->value <= mid_nb)
		{
			pb(stk_a, stk_b);
			last_index = get_last(*stk_a)->index;
		}
		else
			ra(stk_a, 1);
	}
}

void	find_price(t_stk_node *target, t_stk_node **stk_a ,t_stk_node **stk_b, t_stk_node **cheapest)
{
	int	max_a;
	int	max_b;

	max_a = get_last(*stk_a)->index;
	max_b = get_last(*stk_b)->index;
	(*stk_b)->price = 0;
	if (target->index <= max_a / 2)
		(*stk_b)->price += target->index;
	else
		(*stk_b)->price += (max_a + 1) - target->index;
	if ((*stk_b)->index <= max_b / 2)
		(*stk_b)->price += (*stk_b)->index;
	else
		(*stk_b)->price += (max_b + 1) - (*stk_b)->index;
	if ((*stk_b)->price < (*cheapest)->price)
		*cheapest = *stk_b;
		
}

void	find_target(t_stk_node **stk_a, t_stk_node **stk_b, t_stk_node **cheapest)
{
	t_stk_node	*a;
	t_stk_node	*b;

	b = *stk_b;
	while (b)
	{
		a = *stk_a;
		b->target = a;
		while (a)
		{
			/////// ver isto melhor esta logica ........
			// if (a->value > b->value)
			// {
			// 	if (a->value > b->target->value)
			// 		b->target = a;
			// }
			a = a->next;
		}
		find_price(b->target, stk_a, &b, cheapest);
		b = b->next;
	}
}

int	rotate_both(t_stk_node *cheapest, t_stk_node **stk_a, t_stk_node **stk_b, int max_a, int max_b)
{
	if (cheapest->index <= max_b / 2 && cheapest->target->index <= max_a/ 2)
			rr(stk_a, stk_b);
	else if (cheapest->index > max_b / 2 && cheapest->target->index > max_a / 2)
			rrr(stk_a, stk_b);
	else
		return (0);
	return (1);
}

void	push_to_a(t_stk_node *cheapest, t_stk_node **stk_a, t_stk_node **stk_b)
{
	int	max_index_a;
	int	max_index_b;


	max_index_a = get_last(*stk_a)->index;
	max_index_b = get_last(*stk_b)->index;
	while (*stk_b != cheapest || *stk_a != cheapest->target)
	{

		if (!rotate_both(cheapest, stk_a, stk_b, max_index_a, max_index_b))
		{
			if (cheapest->target->index <= max_index_a / 2)
				ra(stk_a, 1);
			else
				rra(stk_a, 1);
			if (cheapest->index <= max_index_b / 2)
				rb(stk_a, 1);
			else
				rrb(stk_a, 1);
		}
		
	}
	pa(stk_a, stk_b);
}

void	ft_push_swap(t_stk_node **stk_a, t_stk_node **stk_b)
{
	t_stk_node	*cheapest;

	push_to_b(stk_a, stk_b);
	sort_three(stk_a);
	while (*stk_b)
	{
		cheapest = *stk_b;
		find_target(stk_a, stk_b, &cheapest);
		push_to_a(cheapest, stk_a, stk_b);
	}
}
