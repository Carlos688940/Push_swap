/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_reverse_rotate_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:46:30 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/15 11:43:54 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static void	rev_rotate_bns(t_snode **stk)
{
	t_snode	*last;

	if (!*stk)
		return ;
	last = get_last_bns(*stk);
	last->nxt = *stk;
	last->prev->nxt = NULL;
	last->prev = NULL;
	(*stk)->prev = last;
	*stk = last;
}

void	rra(t_snode **stk)
{
	rev_rotate_bns(stk);
}

void	rrb(t_snode **stk)
{
	rev_rotate_bns(stk);
}

void	rrr(t_snode **s_a, t_snode **s_b)
{
	rev_rotate_bns(s_a);
	rev_rotate_bns(s_b);
}
