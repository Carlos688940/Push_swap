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

void	find_target(t_stk_node *act, t_stk_node *dst, char stk)
{
	t_stk_node	*a;
	t_stk_node	*d;

	a = act;
	d = dst;
	while (a)
	{
		if (!dst)
			a->target = NULL;
		else
		{
			while (d)
			{
				a->target = d;
				if (stk == 'a')
				{
					if (d->value < a->value)
					{
						if (a->target->value < d->value)
							a->target = d;
						else if (a->target->value > d->value)
							a->target = d;
					}
				}
				else
				{
					if (d->value > a->value)
					{
						if (d->value > a->target->value)
							a->target = a;
						else if (d->value < a->target->value)
							a->target = a;
					}
				}
				d = d->next;
			}
		}
		d = dst;
		a = a->next;
	}
}

void	find_price(t_stk_node *act, t_stk_node *dst, t_stk_node **cheapest)
{
	int	max_ind_act;
	int	max_ind_dst;
	int	mid_point;
	t_stk_node	*ptr;

	*cheapest = NULL;
	ptr = act;
	mid_point = ft_round(get_min(act)->value + get_max(act)->value) / 2;
	max_ind_act = get_last(act)->index;
	if (dst)
		max_ind_dst = get_last(dst)->index;
	while (ptr)
	{
		if (ptr->value <= mid_point)
		{
			if (ptr->index <= max_ind_act / 2)
				ptr->price = ptr->index;
			else
				ptr->price = (max_ind_act - ptr->index) + 1;
			if (dst)
			{
				if (dst->index <= max_ind_dst / 2)
					ptr->price += dst->index;
				else
					ptr->price += (max_ind_dst - dst->index) + 1;

			}	
			if (!(*cheapest))
				*cheapest = ptr;
			else
			{
				if (ptr->price < (*cheapest)->price)
					*cheapest = ptr;
			}
		}
		ptr = ptr->next;
	}
}

void	rotate_stks(t_stk_node **act, t_stk_node **dst, t_stk_node *cheapest)
{
	int	median_act;
	int	median_dst;

	median_act = get_last(*act)->index;
	if (*dst)
		median_dst = get_last(*dst)->index;
	while ((*act != cheapest) && (*dst != cheapest->target))
	{
		if (cheapest->index <= median_act && cheapest->target->index <= median_dst)
			rr(act, dst);
		else
			rrr(act, dst);
	}
	while (*act != cheapest)
	{
		if ((*act)->index <= median_act)
			ra(act, 1);
		else
			rra(act, 1);
	}
	while (*dst != cheapest->target)
	{
		if ((*dst)->index <= median_dst)
			rb(dst, 1);
		else
			rrb(dst, 1);
	}
}

void	push_to_b(t_stk_node **stk_a, t_stk_node **stk_b)
{
	int	max_ind;
	t_stk_node	*cheapest;

	max_ind = get_last(*stk_a)->index;
	while (max_ind > 2)
	{
		find_target(*stk_a, *stk_b, 'a');
		find_price(*stk_a, *stk_b, &cheapest);
		rotate_stks(stk_a, stk_b, cheapest);
		pb(stk_a, stk_b);
		max_ind = get_last(*stk_a)->index;
	}
}

void	ft_push_swap(t_stk_node **stk_a, t_stk_node **stk_b)
{
	// t_stk_node	*cheapest;

	push_to_b(stk_a, stk_b);
	sort_three(stk_a);
	sort_three(stk_a);
}
