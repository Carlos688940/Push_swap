/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:09:27 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/11 14:29:05 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_mid_nb(t_snode **s_a, t_snode **s_b, t_info *inf_a)
{
	while ((*s_a)->val != inf_a->mid_nb->val)
	{
		if (inf_a->mid_nb->ind < inf_a->mid_ind)
			ra(s_a);
		else
			rra(s_a);
	}
	pb(s_a, s_b);
	inf_a->max_ind = get_last(*s_a)->ind;
}

void	find_a_moves(t_snode *s_a, t_info *inf_a, t_lower *lower)
{
	t_moves	moves;

	ft_bzero(&moves, sizeof(t_moves));
	if (s_a->ind < inf_a->mid_ind)
		moves.ra = s_a->ind;
	else
		moves.rra = (inf_a->max_ind + 1) - s_a->ind;
	s_a->cost = moves.ra + moves.rra;
	if (!lower->node || lower->node->cost > s_a->cost)
	{
		lower->node = s_a;
		lower->moves = moves;
	}		
}

void	rotate(t_snode **s_a, t_snode **s_b, t_moves *moves)
{
	while (moves->ra--)
		ra(s_a);
	while (moves->rb--)
		rb(s_b);
	while (moves->rr--)
		rr(s_a, s_b);
	while (moves->rra--)
		rra(s_a);
	while (moves->rrb--)
		rrb(s_b);
	while (moves->rrr--)
		rrr(s_a, s_b);
	ft_bzero(moves, sizeof(t_moves));
}

void	send_half(t_snode **s_a, t_snode **s_b, t_info *inf_a, t_lower *lower)
{
	t_snode *a;

	while (inf_a->max_ind > 2 && inf_a->max_ind >= inf_a->mid_ind)
	{
		a = *s_a;
		while (a)
		{
			if (a->val < inf_a->mid_nb->val)
				find_a_moves(a, inf_a, lower);
			a = a->nxt;
		}
		rotate(s_a, s_b, &lower->moves);
		pb(s_a, s_b);
		rb(s_b);
		ft_bzero(lower, sizeof(t_lower));
		inf_a->max_ind = get_last(*s_a)->ind;
	}
}

void	send_second_half(t_snode **s_a, t_snode **s_b, t_info *inf_a, t_lower *lower)
{
	t_snode *a;
	int	sa_mid;

	sa_mid = inf_a->mid_nb->val;
	while (inf_a->max_ind > 2)
	{
		reset_info_a(*s_a, inf_a);
		a = *s_a;
		while (a)
		{
			if (a->val < inf_a->mid_nb->val)
				find_a_moves(a, inf_a, lower);
			a = a->nxt;
		}	
		rotate(s_a, s_b, &lower->moves);
		pb(s_a, s_b);
		if ((*s_b)->val < sa_mid)
			rb(s_b);
		ft_bzero(lower, sizeof(t_lower));
		inf_a->max_ind = get_last(*s_a)->ind;
	}
}

void	push_to_b(t_snode **s_a, t_snode **s_b, t_info *inf_a, t_lower *lower)
{
	push_mid_nb(s_a, s_b, inf_a);
	send_half(s_a, s_b, inf_a, lower);
	send_second_half(s_a, s_b, inf_a, lower);	
}

void	find_target(t_snode *node, t_snode *s_a)
{
	t_snode	*min;
	t_snode	*max;

	min = get_min(s_a);
	max = get_max(s_a);
	if (node->val > max->val)
		node->tgt = min;
	else
	{
		while (s_a)
		{
			if ((!node->tgt && s_a->val > node->val) || (s_a->val > node->val && s_a->val < node->tgt->val))
				node->tgt = s_a;
			s_a = s_a->nxt;
		}
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

void	find_cost(t_snode *node, t_snode **s_b, t_info *inf_a, t_lower *lower)
{
	int	last_ind;
	t_moves	moves;

	ft_bzero(&moves, sizeof(t_moves));
	last_ind = get_last(*s_b)->ind;
	if (node->ind < (last_ind + 1) / 2.0)
		moves.rb = node->ind;
	else
		moves.rrb = (last_ind + 1) - node->ind;
	if (node->tgt->ind < inf_a->mid_ind)
		moves.ra = node->tgt->ind;
	else
		moves.rra = (inf_a->max_ind + 1) - node->tgt->ind;
	check_both(&moves);
	node->cost = moves.ra + moves.rb + moves.rr + moves.rra + moves.rrb + moves.rrr;
	if (!lower->node || node->cost < lower->node->cost)
	{
		lower->node = node;
		lower->moves = moves;
	}
}

void	push_back(t_snode **s_a, t_snode **s_b, t_info *info, t_lower *lower)
{
	t_snode	*b;

	while (*s_b)
	{
		b = *s_b;
		while (b)
		{
			b->tgt = 0;
			find_target(b, *s_a);
			find_cost(b, s_b, info, lower);
			b = b->nxt;
		}
		rotate(s_a, s_b, &lower->moves);
		pa(s_a, s_b);
		reset_info_a(*s_a, info);
		ft_bzero(lower, sizeof(t_lower));
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