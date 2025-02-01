/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-30 21:15:19 by carlaugu          #+#    #+#             */
/*   Updated: 2025-01-30 21:15:19 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rb(t_stk_node **stk, int x)
{
	t_stk_node	*box;
	t_stk_node	*last;
	
	box = *stk;
	last = get_last(*stk);
	*stk = (*stk)->next;
	(*stk)->previous = NULL;
	box->previous = last;
	box->next = NULL;
	last->next = box;
	define_index(*stk);
	if (x)
	{
		ft_putstr_fd("rb\n", 1);
		abc++;
	}
}

void	rrb(t_stk_node **stk, int x)
{
	t_stk_node	*last;
	
	last = get_last(*stk);
	last->previous->next = NULL;
	last->next = *stk;
	last->previous = NULL;
	*stk = last;
	define_index(*stk);
	if (x)
	{
		ft_putstr_fd("rrb\n", 1);
		abc++;
	}
}

void	sb(t_stk_node **stk, int x)
{
	(*stk)->previous = (*stk)->next;
	(*stk)->next = (*stk)->next->next;
	(*stk)->next->previous = *stk;
	(*stk)->previous->next = *stk;
	*stk = (*stk)->previous;
	(*stk)->previous = NULL;
	define_index(*stk);
	if (x)
	{
		ft_putstr_fd("sb\n", 1);
		abc++;
	}
}

void	pb(t_stk_node **stk_a, t_stk_node **stk_b)
{
	t_stk_node	*box;

	box = *stk_a;
	*stk_a = (*stk_a)->next;
	(*stk_a)->previous = NULL;
	box->next = *stk_b;
	if (*stk_b)
		(*stk_b)->previous = box;
	box->previous = NULL;
	*stk_b = box;
	define_index(*stk_a);
	define_index(*stk_b);
	ft_putstr_fd("pb\n", 1);
	abc++;
}