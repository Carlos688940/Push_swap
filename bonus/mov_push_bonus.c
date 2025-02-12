/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_push_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-12 18:46:09 by carlaugu          #+#    #+#             */
/*   Updated: 2025-02-12 18:46:09 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	push_bns(t_snode **src, t_snode **dst)
{
	t_snode	*box;

	box = *src;
	*src = (*src)->nxt;
	if (*src)
		(*src)->prev = NULL;
	box->nxt = *dst;
	if (*dst)
		(*dst)->prev = box;
	*dst = box;
	define_index_bns(*src);
	define_index_bns(*dst);
}

void	pb(t_snode **s_a, t_snode **s_b)
{
	push_bns(s_a, s_b);
	write(1, "pb\n", 3);
}

void	pa(t_snode **s_a, t_snode **s_b)
{
	push_bns(s_b, s_a);
	write(1, "pa\n", 3);
}
