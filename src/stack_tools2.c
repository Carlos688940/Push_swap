/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:53:54 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/12 11:41:40 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_snode	*get_last(t_snode *stk)
{
	while (stk)
	{
		if (!stk->nxt)
			break ;
		stk = stk->nxt;
	}
	return (stk);
}

t_snode	*get_min(t_snode *stk)
{
	t_snode	*min;

	min = NULL;
	while (stk)
	{
		if (!min || stk->val < min->val)
			min = stk;
		stk = stk->nxt;
	}
	return (min);
}

t_snode	*get_max(t_snode *stk)
{
	t_snode	*max;

	max = NULL;
	while (stk)
	{
		if (!max || stk->val > max->val)
			max = stk;
		stk = stk->nxt;
	}
	return (max);
}

void	reset_info_a(t_snode *s_a, t_info *info)
{
	int	mid_nb;

	info->count = 0;
	info->min = get_min(s_a);
	info->max = get_max(s_a);
	info->max_ind = get_last(s_a)->ind;
	info->mid_ind = (info->max_ind + 1) / 2;
	mid_nb = (info->min->val + info->max->val) / 2;
	find_mid_n(s_a, info, &mid_nb);
	while (s_a)
	{
		if (s_a->val == mid_nb)
		{
			info->mid_nb = s_a;
			break ;
		}
		s_a = s_a->nxt;
	}
}
