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

void	rb(t_stk_node **stk)
{
	t_stk_node	*box;
	
	box = *stk;
	while (*stk)
	{
		if (!(*stk)->next)
		{
			box->next->previous = NULL;
			(*stk)->next = box; 
			box->previous = (*stk)->previous->next;
			(*stk) = (*stk)->previous;
			box->next = NULL;
			break;
		}
		(*stk) = (*stk)->next;
	}
	ft_putstr_fd("rb\n", 1);
}

void	rrb(t_stk_node **stk)
{
	t_stk_node	*last;
	
	last = get_last(*stk);
	last->previous->next = NULL;
	last->next = *stk;
	last->previous = NULL;
	*stk = last;
	ft_putstr_fd("rrb\n", 1);
}


void	sb(t_stk_node **stk)
{
	t_stk_node	*box;

	box = (*stk)->next;
	if (box->next)
		box->next->previous = box->previous;
	box->previous = NULL;
	(*stk)->next = box->next;
	(*stk)->previous = box;		
	box->next = (*stk);
	(*stk) = box;
	ft_putstr_fd("sb\n", 1);
}