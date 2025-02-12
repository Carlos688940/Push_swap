/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-12 19:01:37 by carlaugu          #+#    #+#             */
/*   Updated: 2025-02-12 19:01:37 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	define_index_bns(t_snode *stk)
{
	int	i;

	i = -1;
	while (stk)
	{
		stk->ind = ++i;
		stk = stk->nxt;
	}
}

t_snode	*get_last_bns(t_snode *stk)
{
	while (stk)
	{
		if (!stk->nxt)
			break ;
		stk = stk->nxt;
	}
	return (stk);
}