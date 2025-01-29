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

t_stk_node	*ra(t_stk_node *stk)
{
	t_stk_node	*box;
	
	box = stk;
	while (stk)
	{
		if (!stk->next)
		{
			box->next->previous = NULL;
			stk->next = box; 
			box->previous = stk->previous->next;
			stk = stk->previous;
			box->next = NULL;
			break;
		}
		stk = stk->next;
	}
	ft_putstr_fd("ra\n", 1);
	return (stk);
}

t_stk_node	*rra(t_stk_node *stk)
{
	t_stk_node	*last;
	
	last = get_last(stk);
	last->previous->next = NULL;
	last->next = stk;
	last->previous = NULL;
	stk = last;
	ft_putstr_fd("rra\n", 1);
	return (stk);
}


t_stk_node	*sa(t_stk_node *stk)
{
	t_stk_node	*box;

	if (stk->value > stk->next->value)
	{
		box = stk->next;
		if (box->next)
			box->next->previous = box->previous;
		box->previous = NULL;
		stk->next = box->next;
		stk->previous = box;
		box->next = stk;
		stk = box;
		ft_putstr_fd("sa\n", 1);
	}
	return (stk);
}