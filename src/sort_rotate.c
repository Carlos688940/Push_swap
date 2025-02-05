/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:30:01 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/05 11:16:16 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_snode **stk)
{
	t_snode	*last;

	last = get_last(*stk);
	last->nxt = *stk;
	(*stk)->prev = last;
	*stk = (*stk)->nxt;
	(*stk)->prev = NULL;
	last->nxt->nxt = NULL;
	define_index(*stk);
}

void	ra(t_snode **stk)
{
	rotate(stk);
	write(1, "ra\n", 3);
}

void	rb(t_snode **stk)
{
	rotate(stk);
	write(1, "rb\n", 3);
}

void	rr(t_snode **s_a, t_snode **s_b)
{
	rotate(s_a);
	rotate(s_b);
	write(1, "rr\n", 3);
}