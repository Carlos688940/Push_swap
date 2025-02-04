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

void	find_target(t_stk_node *src, t_stk_node *dst, char stk)
{
	t_stk_node	*d;

	d = dst;
	while (d)
	{
		if (stk == 'a')
		{
			if (!src->target || (d->value < src->value && d->value > src->target->value))
				src->target = d;
		}
		else if (stk == 'b')
		{
			if (!src->target || (d->value > src->value && d->value < src->target->value))
				src->target = d;
		}
		d = d->next;
	}
}

void	find_price(t_stk_node *src, t_stk_node *dst, int size_s, t_moves *moves, t_cheapest *cheapest)
{
	int	size_d;

	if (src->index <= size_s / 2)
		moves->ra = src->index;
	else
		moves->rra = (size_s - src->index) + 1;
	if (dst)
	{
		size_d = get_last(dst)->index;
		if (src->target->index <= size_d / 2)
			moves->rb = src->target->index;
		else
			moves->rrb = (size_d - src->target->index) + 1;
	}
	src->price = moves->ra + moves->rb + moves->rra + moves->rrb;
	while (moves->ra && moves->rb)
	{
		moves->ra--;
		moves->rb--;
		moves->rr++;
		src->price = moves->ra + moves->rb + moves->rr;
	}
	while (moves->rra && moves->rrb)
	{
		moves->rra--;
		moves->rrb--;
		moves->rrr++;
		src->price = moves->rra + moves->rrb + moves->rrr;
	}
	if (!cheapest->cheapest || src->price < cheapest->cheapest->price)
	{
		cheapest->cheapest = src;
		cheapest->moves = *moves;
	}
}

void	rotate(t_stk_node **src, t_stk_node **dst, t_cheapest *cheapest)
{
	while (cheapest->moves.rr--)
		rr(src, dst);
	while (cheapest->moves.rrr--)
		rrr(src, dst);
	while (cheapest->moves.ra--)
		ra(src, 1);
	while (cheapest->moves.rb--)
		rb(src, 1);
	while (cheapest->moves.rra--)
		rra(src, 1);
	while (cheapest->moves.rrb--)
		rrb(src, 1);
}

void	check_last_b(t_stk_node **stk_b)
{
	if ((*stk_b)->value < get_last(*stk_b)->value)
		rb(stk_b, 1);
	if ((*stk_b)->next)
	{
		if ((*stk_b)->value < (*stk_b)->next->value)
			sb(stk_b, 1);
	}
}

void	push_to_b(t_stk_node **stk_a, t_stk_node **stk_b, t_moves *moves, t_cheapest *cheapest)
{
	int	size;
	int	mid_nb;
	t_stk_node	*a;

	a = *stk_a;
	ft_bzero(moves, sizeof(t_moves));
	ft_bzero(cheapest, sizeof(t_cheapest));
	size = get_last(*stk_a)->index;
	mid_nb = (get_min(*stk_a)->value + get_max(*stk_a)->value) / 2;
	while (size > 2)
	{
		while (a)
		{
			if (a->value <= mid_nb)
			{
				a->target = 0;
				find_target(a, *stk_b, 'a');
				find_price(a, *stk_b, size, moves, cheapest);
				ft_bzero(moves, sizeof(t_moves));
			}
			a = a->next;
		}
		rotate(stk_a, stk_b, cheapest);
		pb(stk_a, stk_b);
		check_last_b(stk_b);
		cheapest->cheapest->target = 0;
		ft_bzero(cheapest, sizeof(t_cheapest));
		size = get_last(*stk_a)->index;
		mid_nb = (get_min(*stk_a)->value + get_max(*stk_a)->value) / 2;
		a = *stk_a;
	}
}

void	push_back(t_stk_node **stk_a, t_stk_node **stk_b, t_moves *moves, t_cheapest *cheapest)
{
	int	size_b;
	t_stk_node	*b;

	b = *stk_b;
	size_b = get_last(*stk_b)->index;
	while (*stk_b)
	{
		while (b)
		{
			b->target = 0;
			find_target(b, *stk_a, 'b');
			find_price(b, *stk_a, size_b, moves, cheapest);
			ft_bzero(moves, sizeof(t_moves));
			b = b->next;
		}
		rotate(stk_b, stk_a, cheapest);
		pa(stk_a, stk_b);
		ft_bzero(cheapest, sizeof(t_cheapest));
		b = *stk_b;
	}
}

void	ft_push_swap(t_stk_node **stk_a, t_stk_node **stk_b)
{
	t_cheapest	cheapest;
	t_moves		moves;
	

	push_to_b(stk_a, stk_b, &moves, &cheapest);
	sort_three(stk_a);
	push_back(stk_a, stk_b, &moves, &cheapest);
}
