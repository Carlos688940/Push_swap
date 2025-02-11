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
		if (inf_a->mid_nb->cost < inf_a->mid_ind)
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
		////////////// adicionar um stk_mid e um mid_nb para varias iteracoes
		if (lower->node->val < inf_a->mid_nb->val)
		{
			lower->node = s_a;
			lower->moves = moves;
		}
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

void	push_to_b(t_snode **s_a, t_snode **s_b, t_info *inf_a, t_lower *lower)
{
	t_snode *a;
	int	stk_mid;

	stk_mid = inf_a->mid_nb->val;
	push_mid_nb(s_a, s_b, inf_a);
	send_half(s_a, s_b, inf_a, lower);
	reset_info_a(*s_a, inf_a);
	while (inf_a->max_ind > 2)
	{
		a = *s_a;
		while (a)
		{
			if (a->val < inf_a->mid_nb->val)
				find_a_moves(*s_a, inf_a, lower);
			a = a->nxt;
		}	
		rotate(s_a, s_b, &lower->moves);
		pb(s_a, s_b);
		if ((*s_b)->val < stk_mid)
			rb(s_b);
		ft_bzero(lower, sizeof(t_lower));
		inf_a->max_ind = get_last(*s_a)->ind;
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
}