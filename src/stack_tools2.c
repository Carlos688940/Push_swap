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

t_snode	*get_last(t_snode *stk)
{
	while (stk)
	{
		if (!stk->nxt)
			break;
		stk = stk->nxt;
	}
	return (stk);
}