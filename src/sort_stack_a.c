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

void	ra(t_stk_node *stk)
{
	int	box;
	int	box1;
	
	box1 = stk->value;
	while (stk)
	{
		if (!stk->next)
		{
			stk->value = box1;
			break;
		}
		box = stk->next->value;
		stk->value = box;
		stk = stk->next;
	}
	ft_putstr_fd("ra\n", 1);
}

void	rra(t_stk_node *stk)
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
}

void	sa(t_stk_node *stk)
{
	int	box;

	if (stk->value > stk->next->value)
	{	box = stk->value;
		stk->value = stk->next->value;
		stk->next->value = box;
	}
	else
		return ;
	ft_putstr_fd("sa\n", 1);
}