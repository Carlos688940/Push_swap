/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:09:27 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/12 11:52:22 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	send_half(t_snode **s_a, t_snode **s_b, t_info *inf_a, \
							t_lower *lower)
{
	t_snode		*a;

	while (inf_a->max_ind > 2 && inf_a->max_ind >= inf_a->mid_ind)
	{
		a = *s_a;
		while (a)
		{
			if (a->val < inf_a->mid_nb->val)
				find_a_cost(a, inf_a, lower);
			a = a->nxt;
		}
		rotate_stks(s_a, s_b, &lower->mov);
		pb(s_a, s_b);
		rb(s_b);
		ft_bzero(lower, sizeof(t_lower));
		inf_a->max_ind = get_last(*s_a)->ind;
	}
}

static void	send_second_half(t_snode **s_a, t_snode **s_b, t_info *inf_a, \
								t_lower *lower)
{
	t_snode		*a;
	int			sa_mid;

	sa_mid = inf_a->mid_nb->val;
	while (inf_a->max_ind > 2)
	{
		reset_info_a(*s_a, inf_a);
		a = *s_a;
		while (a)
		{
			if (a->val < inf_a->mid_nb->val)
				find_a_cost(a, inf_a, lower);
			a = a->nxt;
		}
		rotate_stks(s_a, s_b, &lower->mov);
		pb(s_a, s_b);
		if ((*s_b)->val < sa_mid)
			rb(s_b);
		ft_bzero(lower, sizeof(t_lower));
		inf_a->max_ind = get_last(*s_a)->ind;
	}
}

static void	push_to_b(t_snode **s_a, t_snode **s_b, t_info *inf_a, \
							t_lower *lower)
{
	push_mid_nb(s_a, s_b, inf_a);
	send_half(s_a, s_b, inf_a, lower);
	send_second_half(s_a, s_b, inf_a, lower);
}

static void	push_back(t_snode **s_a, t_snode **s_b, t_info *info, \
							t_lower *lower)
{
	t_snode	*b;

	while (*s_b)
	{
		b = *s_b;
		while (b)
		{
			b->tgt = 0;
			find_target(b, *s_a);
			find_b_cost(b, s_b, info, lower);
			b = b->nxt;
		}
		rotate_stks(s_a, s_b, &lower->mov);
		pa(s_a, s_b);
		reset_info_a(*s_a, info);
		ft_bzero(lower, sizeof(t_lower));
	}
}

void	ft_push_swap(t_snode **s_a, t_snode **s_b)
{
	t_info	info_a;
	t_lower	lower;

	ft_bzero(&info_a, sizeof(t_info));
	ft_bzero(&lower, sizeof(t_lower));
	reset_info_a(*s_a, &info_a);
	push_to_b(s_a, s_b, &info_a, &lower);
	sort_three(s_a);
	push_back(s_a, s_b, &info_a, &lower);
	while ((*s_a) != info_a.min)
	{
		if (info_a.min->ind < info_a.mid_ind)
			ra(s_a);
		else
			rra(s_a);
	}
}
