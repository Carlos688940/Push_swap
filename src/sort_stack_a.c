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

void	define_index(t_stk_node *stk)
{
	int	i;

	i = -1;
	while (stk)
	{
		stk->index = ++i;
		stk = stk->next;
	}
}

int	get_last(t_stk_node *stk)
{
	int	n;

	while (stk)
	{
		n = stk->value;
		stk = stk->next;
	}
	return (n);
}

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
	define_index(stk);
	ft_putstr_fd("ra\n", 1);
	return (stk);
}

t_stk_node	*rra(t_stk_node *stk)
{
	int	box;
	int	box1;
	
	box1 = get_last(stk);
	while (stk)
	{
		box = stk->value;
		stk->value = box1;
		box1 = box;		
		stk = stk->next;
	}
	ft_putstr_fd("rra\n", 1);
	return (stk);
}


t_stk_node	*sa(t_stk_node *stk)
{
	t_stk_node	*box;

	if (stk->value > stk->next->value)
	{
		box = stk->next;
		stk->previous =  box;
		stk->next = NULL;
		box->next = stk;
		box->previous = NULL;
		stk = box;
		define_index(stk);
		ft_putstr_fd("sa\n", 1);
	}
	return (stk);
}