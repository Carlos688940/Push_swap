/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:44:52 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/12 11:47:11 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include <stdio.h>

static void	swap(t_snode **stk)
{
	t_snode	*box;

	box = *stk;
	*stk = (*stk)->nxt;
	(*stk)->prev = NULL;
	box->nxt = (*stk)->nxt;
	box->prev = *stk;
	(*stk)->nxt->prev = box;
	(*stk)->nxt = box;
	define_index(*stk);
}

void	sa(t_snode **stk)
{
	swap(stk);
	write (1, "sa\n", 3);
}

void	sb(t_snode **stk)
{
	swap(stk);
	write (1, "sb\n", 3);
}

void	ss(t_snode **s_a, t_snode **s_b)
{
	swap(s_a);
	swap(s_b);
	write (1, "ss\n", 3);
}
