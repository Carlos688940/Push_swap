/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 18:53:03 by carlaugu          #+#    #+#             */
/*   Updated: 2025-01-27 18:53:03 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stk_node *stk)
{
	int	box;

	if (stk->value > stk->next->value)
	{	box = stk->value;
		stk->value = stk->next->value;
		stk->next->value = box;
	}
	ft_putstr_fd("sa\n", 1);
}