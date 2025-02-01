/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:53:03 by carlaugu          #+#    #+#             */
/*   Updated: 2025/01/28 14:13:59 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stk_node **stk, int x)
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
		ft_putstr_fd("ra\n", 1);
		abc++;
	}
}

void	rra(t_stk_node **stk, int x)
{
	t_stk_node	*last;
	
	last = get_last(*stk);
	last->previous->next = NULL;
	last->next = *stk;
	last->previous = NULL;
	(*stk)->previous = last;
	*stk = last;
	define_index(*stk);
	if (x)
	{
		ft_putstr_fd("rra\n", 1);
		abc++;
	}
}


void	sa(t_stk_node **stk, int x)
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
		ft_putstr_fd("sa\n", 1);
		abc++;
	}
}

void	pa(t_stk_node **stk_a, t_stk_node **stk_b)
{
	t_stk_node	*box;

	box = *stk_b;
	*stk_b = (*stk_b)->next;
	if (*stk_b)
		(*stk_b)->previous = NULL;
	box->next = *stk_a;
	if (*stk_a)
		(*stk_a)->previous = box;
	box->previous = NULL;
	*stk_a = box;
	define_index(*stk_a);
	define_index(*stk_b);
	ft_putstr_fd("pa\n", 1);
	abc++;
}