/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:53:54 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/06 15:52:00 by carlaugu         ###   ########.fr       */
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

int	get_min(t_snode *stk)
{
	int	min;

	min = INT_MAX;
	while (stk)
	{
		if (stk->val < min)
			min = stk->val;
		stk = stk->nxt;
	}
	return (min);
}

int	get_max(t_snode *stk)
{
	int	max;

	max = INT_MIN;
	while (stk)
	{
		if (stk->val > max)
			max = stk->val;
		stk = stk->nxt;
	}
	return (max);
}

void	reset_info_a(t_snode *s_a ,t_info *info)
{
	info->count = 0;	
	info->max_ind = get_last(s_a)->ind;
	info->mid_ind = (info->max_ind + 1) / 2; 
	info->max = get_max(s_a);
	info->min = get_min(s_a);
	info->mid_nb = (info->min + info->max) / 2;
	find_mid_n(s_a, info);
}