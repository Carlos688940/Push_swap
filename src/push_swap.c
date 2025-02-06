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

void	find_tgt(t_snode *src, t_snode *dst, char tgt)
{
	(void)src;
	while (dst)
	{
		if (tgt == 'b')
		{
			if (!src->tgt || src->tgt->val > src->val || (dst->val < src->val && dst->val > src->tgt->val))
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
	check_both(moves);
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

void	find_price(t_snode *stk, t_moves *moves, t_info *info_a, t_snode **cheapest)
{	
	int	last_ind;

	last_ind = get_last(stk)->ind;
	if (stk->ind <= ft_round(last_ind / 2))
		moves->rb = stk->ind;
	else
		moves->rrb = (last_ind - stk->ind) + 1;
	if (stk->tgt->ind <= info_a->mid_ind)
		moves->ra = stk->tgt->ind;
	else
		moves->rra = (info_a->lst_ind - stk->tgt->ind) + 1;
	if (!*cheapest || (*cheapest)->cost > stk->cost)
		*cheapest = stk;		
}

void	push_back(t_snode **s_a, t_snode **s_b, t_info *info, t_moves *moves)
{
	t_snode	*cheapest;

	reset_info_a(*s_a, info);
	while (*s_b)
	{
		find_tgt(*s_b, *s_a, 'a');
		find_price(*s_b, moves, info, &cheapest);
	}
}

void	find_moves(t_snode *tgt,t_snode **stk_b, t_moves *moves)
{
	int	last_ind;

	last_ind = get_last(*stk_b)->ind;
	if (tgt->ind <= ft_round(last_ind / 2))
		moves->rb = tgt->ind;
	else
		moves->rrb = (last_ind - tgt->ind) + 1;
}

void	push_to_b(t_snode **s_a, t_snode **s_b, t_info *info_a, t_moves *moves)
{
	info_a->count = 0;
	while (info_a->lst_ind > 2 && info_a->count < info_a->mid_ind)
	{
		if ((*s_a)->val < info_a->mid_nb)
		{
			info_a->count++;
			find_tgt(*s_a, *s_b, 'b');
			if ((*s_a)->tgt)
			{
				find_moves((*s_a)->tgt, s_b, moves);
				rotate(s_a, s_b, moves);
			}
			pb(s_a, s_b);
			info_a->lst_ind = get_last(*s_a)->ind;
		}
		else
			ra(s_a);
	}
	////// ainda tem mais de 3 e vai ate ter 3 /////////
	while (info_a->lst_ind > 2)
	{
		reset_info_a(*s_a, info_a);
		if ((*s_a)->val < info_a->mid_nb)
		{
			find_tgt(*s_a, *s_b, 'b');
			// if ((*s_a)->tgt)
			// 	rotate(s_b, (*s_a)->tgt, 'b');
			pb(s_a, s_b);
			info_a->lst_ind = get_last(*s_a)->ind;
		}
		else
			ra(s_a);
	}
}

void	ft_push_swap(t_snode **s_a, t_snode **s_b)
{
	t_moves	moves;
	t_info	info_a;

	ft_bzero(&moves, sizeof(t_moves));
	ft_bzero(&info_a, sizeof(t_info));
	reset_info_a(*s_a, &info_a);
	push_to_b(s_a, s_b, &info_a, &moves);
	sort_three(s_a);
	push_back(s_a, s_b, &info_a, &moves);
}