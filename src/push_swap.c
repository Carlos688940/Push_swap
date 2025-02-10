/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:09:27 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/06 18:03:52 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include  <stdio.h>

void	find_tgt(t_snode *src, t_snode *dst, char tgt)
{
	int	max;
	int	min;
	
	min = get_min(dst);		
	max = get_max(dst);
	(void)src;
	while (dst)
	{
		if (tgt == 'b')
		{
			if (src->val < min)
			{
				if (dst->val == max)
					src->tgt = dst;
			}
			else if (!src->tgt || (dst->val < src->val && dst->val > src->tgt->val) || src->tgt->val > src->val)
				src->tgt = dst;
		}
		else if (tgt == 'a')
		{
			if (!src->tgt || src->tgt->val < src->val || (dst->val > src->val && dst->val < src->tgt->val))
				src->tgt = dst;
		}
		dst = dst->nxt;
	}
}

void	check_both(t_moves *moves)
{
	while (moves->ra && moves->rb)
	{
		moves->ra--;
		moves->rb--;
		moves->rr++;
	}
	while (moves->rra && moves->rrb)
	{
		moves->rra--;
		moves->rrb--;
		moves->rrr++;
	}
}

void	rotate(t_snode **s_a, t_snode **s_b, t_moves *moves)
{
	while (moves->rr--)
		rr(s_a, s_b);
	while (moves->rrr--)
		rrr(s_a, s_b);
	while (moves->ra--)
		ra(s_a);
	while (moves->rb--)
		rb(s_b);	
	while (moves->rra--)
		rra(s_a);
	while (moves->rrb--)
		rrb(s_b);
	ft_bzero(moves, sizeof(t_moves));
}

void	find_price(t_snode *node, t_info *info_a, t_snode *s_b, t_lower *lower, char tgt)
{
	int	size_b;
	t_moves	moves;
	(void)s_b;

	size_b = 0;
	ft_bzero(&moves, sizeof(t_moves));
	if (s_b)
		size_b = get_last(s_b)->ind + 1;
	if (tgt == 'b')
	{
		if (node->ind < info_a->mid_ind)
			moves.ra = node->ind;
		else
			moves.rra = (info_a->max_ind + 1) - node->ind;
	}
	else if (tgt == 'a')
	{
		if (node->ind < size_b / 2.0)
			moves.rb = node->ind;
		else
			moves.rrb = size_b - node->ind;
		if (node->tgt->ind < info_a->mid_ind)
			moves.ra = node->tgt->ind;
		else
			moves.rra = (info_a->max_ind + 1) - node->tgt->ind;
	}
	node->cost = moves.ra + moves.rb + moves.rr + moves.rra + moves.rrb + moves.rrr;
	if (!lower->node || lower->node->cost > node->cost)
	{
		lower->node = node;
		lower->moves = moves;
	}
}

void	check_b(t_snode **s_b)
{
	int	lst_val;

	lst_val = get_last(*s_b)->val;
	if ((*s_b)->val < lst_val)
		rb(s_b);
	else if ((*s_b)->nxt && (*s_b)->val < (*s_b)->nxt->val)
		sb(s_b);
}

void	push_back(t_snode **s_a, t_snode **s_b, t_info *info, t_lower *lower)
{
	t_snode	*b;

	reset_info_a(*s_a, info);
	while (*s_b)
	{
		b = *s_b;
		while (b)
		{
			b->tgt = 0;
			find_tgt(b, *s_a, 'a');
			find_price(b, info, *s_b, lower, 'a');
			b = b->nxt;
		}
		rotate(s_a, s_b, &lower->moves);
		pa(s_a, s_b);
		ft_bzero(lower, sizeof(t_lower));
		info->max_ind = get_last(*s_a)->ind;
		info->mid_ind = (info->max_ind + 1) / 2;
	}
	
}

void	push_to_b(t_snode **s_a, t_snode **s_b, t_info *info_a, t_lower *lower)
{
	t_snode	*a;
	int	size_a;

	size_a = info_a->max_ind + 1;
	while (*s_a && info_a->max_ind >= size_a / 2)
	{
		a = *s_a;
		while (a)
		{
			if (a->val < info_a->mid_nb)
			{
				a->tgt = 0;
				// find_tgt(a, *s_b, 'b');
				find_price(a, info_a, *s_b, lower, 'b');
			}
			a = a->nxt;
		}
		rotate(s_a, s_b, &lower->moves);
		pb(s_a, s_b);
		check_b(s_b);
		ft_bzero(lower, sizeof(t_lower));
		info_a->max_ind = get_last(*s_a)->ind;
		info_a->mid_ind = (info_a->max_ind + 1) / 2;
	}
	reset_info_a(*s_a, info_a);
	while (info_a->max_ind > 2)
	{
		a = *s_a;
		while (a)
		{
			a->tgt = 0;
			// find_tgt(a, *s_b, 'b');
			find_price(a, info_a, *s_b, lower, 'b');
			a = a->nxt;
		}
		rotate(s_a, s_b, &lower->moves);
		pb(s_a, s_b);
		check_b(s_b);
		ft_bzero(lower, sizeof(t_lower));
		info_a->max_ind = get_last(*s_a)->ind;
		info_a->mid_ind = (info_a->max_ind + 1) / 2;
	}
}

void	ft_push_swap(t_snode **s_a, t_snode **s_b)
{
	t_info	info_a;
	t_lower	lower;

	ft_bzero(&info_a, sizeof(t_info));
	ft_bzero(&lower, sizeof(t_lower));
	reset_info_a(*s_a, &info_a);
	push_to_b(s_a, s_b, &info_a, &lower);
	sort_three(s_a);
	push_back(s_a, s_b, &info_a, &lower);
}