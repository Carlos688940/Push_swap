/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:09:27 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/05 14:24:09 by carlaugu         ###   ########.fr       */
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

void	push_to_b(t_snode **s_a, t_snode **s_b)
{
	int	mid_n;
	int	lst_ind;
	int	lst_ind_b;

	mid_n = (get_min(*s_a) + get_max(*s_a)) / 2;
	lst_ind = get_last(*s_a)->ind;
	lst_ind_b = 0;
	while (lst_ind > 2)
	{
		if ((*s_a)->val <= mid_n)
		{
			find_tgt(*s_a, *s_b, 'b');
			if ((*s_a)->tgt && lst_ind_b >= 1)
			{
				if ((*s_a)->tgt->ind == 1)
					sb(s_b);
				else if ((*s_a)->tgt->ind <= lst_ind_b / 2)
					rb(s_b);
				else
					rrb(s_b);
			}
			pb(s_a, s_b);
			lst_ind_b = get_last(*s_b)->ind;
			lst_ind = get_last(*s_a)->ind;
		}
		else
			ra(s_a);
	}
}

void	ft_push_swap(t_snode **s_a, t_snode **s_b)
{
	// t_moves	moves;

	push_to_b(s_a, s_b);
	sort_three(s_a);
}