/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:18:07 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/13 18:49:41 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static void	moves_swap(t_snode **s_a, t_snode **s_b, char *cmd)
{
	if (!cmp("sa\n", cmd))
		sa(s_a);
	else if (!cmp("sb\n", cmd))
		sb(s_b);
	else
		ss(s_a, s_b);
}

static void	moves_rotate(t_snode **s_a, t_snode **s_b, char *cmd)
{
	if (!cmp("ra\n", cmd))
		ra(s_a);
	else if (!cmp("rb\n", cmd))
		rb(s_b);
	else
		rr(s_a, s_b);
}

static void	moves_rev_rotate(t_snode **s_a, t_snode **s_b, char *cmd)
{
	if (!cmp("rra\n", cmd))
		rra(s_a);
	else if (!cmp("rrb\n", cmd))
		rrb(s_b);
	else
		rrr(s_a, s_b);
}

static void	moves_push(t_snode **s_a, t_snode **s_b, char *cmd)
{
	if (!cmp("pa\n", cmd))
		pa(s_a, s_b);
	else
		pb(s_a, s_b);
}

int	rotate_stks_bns(t_snode **s_a, t_snode **s_b, t_cmd *lst)
{
	t_cmd	*box;

	box = NULL;
	while (lst)
	{
		if (!cmp(lst->cmd, "sa\n") || !cmp(lst->cmd, "sb\n") \
								|| !cmp(lst->cmd, "ss\n"))
			moves_swap(s_a, s_b, lst->cmd);
		else if (!cmp(lst->cmd, "ra\n") || !cmp(lst->cmd, "rb\n") \
								|| !cmp(lst->cmd, "rr\n"))
			moves_rotate(s_a, s_b, lst->cmd);
		else if (!cmp(lst->cmd, "pa\n") || !cmp(lst->cmd, "pb\n"))
			moves_push(s_a, s_b, lst->cmd);
		else if (!cmp(lst->cmd, "rra\n") || !cmp(lst->cmd, "rrb\n") \
								|| !cmp(lst->cmd, "rrr\n"))
			moves_rev_rotate(s_a, s_b, lst->cmd);
		else
			return (1);
		box = lst->nxt;
		free (lst->cmd);
		free (lst);
		lst = box;
	}
	return (0);
}
