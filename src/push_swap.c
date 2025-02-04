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

void	find_tgt(t_snode *src, t_snode *dst, char tgt)
{
	while (dst)
	{
		if (tgt == 'b')
		{
			if (!src->tgt || src->tgt->val > src->val || (dst->val > src->tgt->val && dst->val < src->val))
				src->tgt = dst;
		}
		else if (tgt == 'a')
			if (!src->tgt || src->tgt->val < src->val || (dst->val < src->tgt->val && dst->val > src->val))
				src->tgt = dst;
		dst = dst->nxt;
	}
}

void	check_price(t_snode *stk)
{
	while (stk->moves.ra && stk->moves.rb)
	{
		stk->moves.ra--;
		stk->moves.rb--;
		stk->moves.rr++;
		stk->cost = stk->moves.ra + stk->moves.rb + stk->moves.rr;
	}
	while (stk->moves.rra && stk->moves.rrb)
	{
		stk->moves.rra--;
		stk->moves.rrb--;
		stk->moves.rrr++;
		stk->cost = stk->moves.rra + stk->moves.rrb + stk->moves.rrr;
	}
}

static	void	cost_a(t_snode *s_a, t_snode *s_b, int max_a, int max_b)
{
	if (s_a->ind <= max_a / 2)
		s_a->moves.ra = s_a->ind;
	else
		s_a->moves.rra = (max_a - s_a->ind) + 1;
	if (s_b)
	{
		if (s_b->ind <= max_b / 2)
			s_a->moves.rb = s_b->ind;
		else
			s_a->moves.rrb = (max_b - s_b->ind) + 1;
	}
	s_a->cost = s_a->moves.ra + s_a->moves.rra + s_a->moves.rb + s_a->moves.rrb;
	check_price(s_a);
}

static	void	cost_b(t_snode *s_a, t_snode *s_b, int max_a, int max_b)
{
	if (s_a->ind <= max_a / 2)
		s_b->moves.ra = s_a->ind;
	else
		s_b->moves.rra = (max_a - s_a->ind) + 1;
	if (s_b->ind <= max_b / 2)
		s_b->moves.rb = s_b->ind;
	else
		s_b->moves.rrb = (max_b - s_b->ind) + 1;
	s_b->cost = s_b->moves.ra + s_b->moves.rra + s_b->moves.rb + s_b->moves.rrb;
	check_price(s_b);
}

void	find_cost(t_snode *s_a, t_snode *s_b, char stk, t_snode **lower)
{
	int	max_a;
	int	max_b;

	max_a = get_last(s_a)->ind;
	if (s_b)
		max_b = get_last(s_b)->ind;
	if (stk == 'a')
	{
		cost_a(s_a, s_b, max_a, max_b);
		if (!*lower || (*lower)->cost > s_a->cost)
			*lower = s_a;
	}
	else if (stk == 'b')
	{
		cost_b(s_a, s_b, max_a, max_b);
		if (!*lower || (*lower)->cost > s_b->cost)
			*lower = s_b;
	}

}

void	push_to_b(t_snode **s_a, t_snode **s_b)
{
	int	mid_n;
	t_snode	*a;
	t_snode	*lower;

	(void)mid_n;
	lower = 0;
	mid_n = (get_min(*s_a) + get_max(*s_a)) / 2;
	a = *s_a;
	while (a)
	{
		if (a->val <= mid_n)
		{
			a->tgt = 0;
			find_tgt(a, *s_b, 'b');
			find_cost(a, *s_b, 'a', &lower);
		}
		a = a->nxt;
	}
	lower = 0;
}

void	ft_push_swap(t_snode **s_a, t_snode **s_b)
{
	push_to_b(s_a, s_b);
}