/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managing_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:00:33 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/12 11:55:50 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	check_both(t_moves *moves)
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

void	rotate_stks(t_snode **s_a, t_snode **s_b, t_moves *moves)
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

void	find_a_cost(t_snode *s_a, t_info *inf_a, t_lower *lower)
{
	t_moves	mov;

	ft_bzero(&mov, sizeof(t_moves));
	if (s_a->ind < inf_a->mid_ind)
		mov.ra = s_a->ind;
	else
		mov.rra = (inf_a->max_ind + 1) - s_a->ind;
	s_a->cost = mov.ra + mov.rra;
	if (!lower->node || lower->node->cost > s_a->cost)
	{
		lower->node = s_a;
		lower->mov = mov;
	}
}

void	find_b_cost(t_snode *node, t_snode **s_b, t_info *inf_a, t_lower *lower)
{
	int		last_ind;
	t_moves	mov;

	ft_bzero(&mov, sizeof(t_moves));
	last_ind = get_last(*s_b)->ind;
	if (node->ind < (last_ind + 1) / 2.0)
		mov.rb = node->ind;
	else
		mov.rrb = (last_ind + 1) - node->ind;
	if (node->tgt->ind < inf_a->mid_ind)
		mov.ra = node->tgt->ind;
	else
		mov.rra = (inf_a->max_ind + 1) - node->tgt->ind;
	check_both(&mov);
	node->cost = mov.ra + mov.rb + mov.rr + mov.rra + mov.rrb + mov.rrr;
	if (!lower->node || node->cost < lower->node->cost)
	{
		lower->node = node;
		lower->mov = mov;
	}
}
