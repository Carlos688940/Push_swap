/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-29 10:53:54 by carlaugu          #+#    #+#             */
/*   Updated: 2025-01-29 10:53:54 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stk_node	*get_last(t_stk_node *stk)
{
	// t_stk_node	*last;

	while (stk)
	{
		if (!stk->next)
			break;
		stk = stk->next;
	}
	return (stk);
}