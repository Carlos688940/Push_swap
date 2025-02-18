/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:46:35 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/15 14:49:05 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static void	rotate_bns(t_snode **stk)
{
	t_snode	*last;

	if (!*stk || !(*stk)->nxt)
		return ;
	last = get_last_bns(*stk);
	last->nxt = *stk;
	(*stk)->prev = last;
	*stk = (*stk)->nxt;
	(*stk)->prev = NULL;
	last->nxt->nxt = NULL;
}

void	ra(t_snode **stk)
{
	rotate_bns(stk);
}

void	rb(t_snode **stk)
{
	rotate_bns(stk);
}

void	rr(t_snode **s_a, t_snode **s_b)
{
	if (!*s_a || !(*s_a)->nxt || !*s_b || !(*s_b)->nxt)
		return ;
	rotate_bns(s_a);
	rotate_bns(s_b);
}
