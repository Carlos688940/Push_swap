/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_swap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:46:39 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/15 11:44:01 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static void	swap_bns(t_snode **stk)
{
	t_snode	*box;

	if (!*stk || !(*stk)->nxt)
		return ;
	box = *stk;
	*stk = (*stk)->nxt;
	(*stk)->prev = NULL;
	box->nxt = (*stk)->nxt;
	box->prev = *stk;
	if ((*stk)->nxt)
		(*stk)->nxt->prev = box;
	(*stk)->nxt = box;
}

void	sa(t_snode **stk)
{
	swap_bns(stk);
}

void	sb(t_snode **stk)
{
	swap_bns(stk);
}

void	ss(t_snode **s_a, t_snode **s_b)
{
	swap_bns(s_a);
	swap_bns(s_b);
}
