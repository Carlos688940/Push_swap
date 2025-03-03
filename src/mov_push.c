/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:10:38 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/12 11:46:15 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_snode **src, t_snode **dst)
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
	define_index(*src);
	define_index(*dst);
}

void	pb(t_snode **s_a, t_snode **s_b)
{
	push(s_a, s_b);
	write(1, "pb\n", 3);
}

void	pa(t_snode **s_a, t_snode **s_b)
{
	push(s_b, s_a);
	write(1, "pa\n", 3);
}
