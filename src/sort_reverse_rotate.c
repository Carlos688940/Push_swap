/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:31:04 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/05 11:14:33 by carlaugu         ###   ########.fr       */
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
	/////////////////////7
	abc += 1;
}

void	rra(t_snode **stk)
{
	rev_rotate(stk);
	write(1, "rra\n", 4);
}

void	rrb(t_snode **stk)
{
	rev_rotate(stk);
	write(1, "rrb\n", 4);
}

void	rrr(t_snode **s_a, t_snode **s_b)
{
	rev_rotate(s_a);
	rev_rotate(s_b);
	write(1, "rrr\n", 4);
	/////////////////////
	abc -= 1;
}