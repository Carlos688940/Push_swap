/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:08:35 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/12 11:48:15 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
			if ((!node->tgt && s_a->val > node->val) \
					|| (s_a->val > node->val && s_a->val < node->tgt->val))
				node->tgt = s_a;
			s_a = s_a->nxt;
		}
	}
}

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
