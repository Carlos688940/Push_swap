/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-04 20:31:04 by carlaugu          #+#    #+#             */
/*   Updated: 2025-02-04 20:31:04 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rev_rotate(t_snode **stk)
{
	t_snode	*last;

	last = get_last(*stk);
	last->nxt = *stk;
	last->prev->nxt = NULL;
	last->prev = NULL;
	(*stk)->prev = last;
	*stk = last;
	define_index(*stk);
}

void	rra(t_snode **stk, int i)
{
	rev_rotate(stk);
	if (i)
		write(1, "rra\n", 4);
}

void	rrb(t_snode **stk, int i)
{
	rev_rotate(stk);
	if (i)
		write(1, "rrb\n", 4);
}

void	rrr(t_snode **s_a, t_snode **s_b)
{
	rra(s_a, 0);
	rrb(s_b, 0);
	write(1, "rrr\n", 4);
}