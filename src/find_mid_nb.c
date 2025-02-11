/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mid_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:28:11 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/11 13:20:02 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	increase_mid(t_snode *s_a, int new_mid, t_info *info, int *mid_nb)
{
	int	nb_nxt;
	t_snode	*a;

	*mid_nb = new_mid;
	while (info->count < info->mid_ind)
	{
		nb_nxt = INT_MAX;
		info->count = 0;	
		a = s_a;
		while (a)
		{
			if (a->val > *mid_nb && a->val < nb_nxt) 
				nb_nxt = a->val;
			if (a->val < *mid_nb)
				info->count++;
			a = a->nxt;		
		}
		if (info->count < info->mid_ind)
			*mid_nb = nb_nxt;
	}
}

static	void	decrease_mid(t_snode *s_a, int new_mid, t_info *info, int *mid_nb)
{
	t_snode	*a;
	int	nb_prev;

	*mid_nb = new_mid;
	while (info->count > info->mid_ind)
	{
		nb_prev = INT_MIN;
		info->count = 0;
		a = s_a;
		while (a)
		{
			if (a->val < *mid_nb && a->val > nb_prev)
				nb_prev = a->val;
			if (a->val < *mid_nb)
				info->count++;
			a= a->nxt;
		}
		if (info->count > info->mid_ind)
			*mid_nb = nb_prev;
	}
}

void	find_mid_n(t_snode *s_a, t_info *info, int *mid_nb)
{
	int	nb_prev;
	int	nb_nxt;
	t_snode	*a;

	nb_prev = INT_MIN;
	nb_nxt = INT_MAX;
	a = s_a;
	while (a)
	{
		if ((a->val > nb_prev) && (a->val < *mid_nb))
			nb_prev = a->val;
		else if ((a->val < nb_nxt) && (a->val > *mid_nb))
			nb_nxt = a->val;
		if (a->val <= *mid_nb)
			info->count++;
		a = a->nxt;
	}
	if (info->count == info->mid_ind)
		*mid_nb = nb_nxt;
	else if (info->count < info->mid_ind)
		increase_mid(s_a, nb_nxt, info, mid_nb);
	else
		decrease_mid(s_a, nb_prev, info, mid_nb);
}