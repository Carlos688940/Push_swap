/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:09:27 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/05 14:24:09 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	find_tgt(t_snode *src, t_snode *dst, char tgt)
{
	(void)src;
	while (dst)
	{
		if (tgt == 'b')
		{
			if (!src->tgt || src->tgt->val > src->val || (dst->val < src->val && dst->val > src->tgt->val))
			src->tgt = dst;
		}
		else if (tgt == 'a')
		{
			if (!src->tgt || src->tgt->val < src->val || (dst->val > src->val && dst->val < src->tgt->val))
				src->tgt = dst;
		}
		dst = dst->nxt;
	}
}

int	ft_round(float i)
{
	return (i + 0.5);
}


// int	increase_mid(t_snode *s_a, int mid_nxt)
// {
// 	int	mid;
// 	int	count;
// 	t_snode	*a;

// 	a = s_a;
// 	mid = (mid_nxt + get_max(s_a)) / 2;
// 	while (a)
// 	{
		// enquanto count nao é igual a lst_ind / 2, deve 
		// ir aumentando o ponto medio
// 	}
// }

int	find_mid_n(t_snode *s_a, int lst_ind)
{
	int	mid_n;
	int	count;
	int	min_befor;
	int	min_after;
	t_snode	*a;

	(void)lst_ind;
	a = s_a;
	count = 0;
	min_befor = INT_MIN;
	min_after = INT_MAX;
	mid_n = (get_min(a) + get_max(a)) / 2;
	while (a)
	{
		if (a->val < mid_n && min_befor < mid_n && a->val > min_befor)
			min_befor = a->val;
		if ((a->val > get_min(s_a)) && (a->val < get_max(s_a)) && (a->val < min_after) && a->val > mid_n)
			min_after = a->val;
		if (a->val < mid_n)
			count++;
		a = a->nxt;
	}
	// if (count < ft_round(lst_ind / 2.0))
	// 	mid_n = increase_mid(s_a, min_after);
	// else if (count > ft_round(lst_ind / 2.0))
	// 	mid_n = decrease_mid(min_befor);
	return (mid_n);
}

void	push_to_b(t_snode **s_a, t_snode **s_b)
{
	int	mid_n;
	int	lst_ind;
	int	lst_ind_b;

	lst_ind = get_last(*s_a)->ind;
	mid_n = find_mid_n(*s_a, lst_ind);
	lst_ind_b = 0;
	while (lst_ind > 2)
	{
		if ((*s_a)->val <= mid_n)
		{
			find_tgt(*s_a, *s_b, 'b');
			if ((*s_a)->tgt && lst_ind_b >= 1)
			{
				if ((*s_a)->tgt->ind == 1)
					sb(s_b);
				else if ((*s_a)->tgt->ind <= lst_ind_b / 2)
					rb(s_b);
				else
					rrb(s_b);
			}
			pb(s_a, s_b);
			lst_ind_b = get_last(*s_b)->ind;
			lst_ind = get_last(*s_a)->ind;
			mid_n = (get_min(*s_a) + get_max(*s_a)) / 2;
		}
		else
			ra(s_a);
	}
}

void	ft_push_swap(t_snode **s_a, t_snode **s_b)
{
	// t_moves	moves;

	push_to_b(s_a, s_b);
	sort_three(s_a);
}