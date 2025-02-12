/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_reverse_rotate_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-12 18:46:30 by carlaugu          #+#    #+#             */
/*   Updated: 2025-02-12 18:46:30 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static void	rev_rotate_bns(t_snode **stk)
{
	t_snode	*last;

	last = get_last_bns(*stk);
	last->nxt = *stk;
	last->prev->nxt = NULL;
	last->prev = NULL;
	(*stk)->prev = last;
	*stk = last;
	define_index_bns(*stk);
}

void	rra(t_snode **stk)
{
	rev_rotate_bns(stk);
	write(1, "rra\n", 4);
}

void	rrb(t_snode **stk)
{
	rev_rotate_bns(stk);
	write(1, "rrb\n", 4);
}

void	rrr(t_snode **s_a, t_snode **s_b)
{
	rev_rotate_bns(s_a);
	rev_rotate_bns(s_b);
	write(1, "rrr\n", 4);
}
