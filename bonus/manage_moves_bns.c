/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_moves_bns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:18:07 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/13 14:42:04 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static void	moves_swap(t_snode **s_a, t_snode **s_b, char *line)
{
	if (!cmp("sa", line, 2))
		sa(s_a);
	else if (!cmp("sb", line, 2))
		sb(s_b);
	else
		ss(s_a, s_b);
}

static void	moves_rotate(t_snode **s_a, t_snode **s_b, char *line)
{
	if (!cmp("ra", line, 2))
		ra(s_a);
	else if (!cmp("rb", line, 2))
		rb(s_b);
	else
		rr(s_a, s_b);
}

static void	moves_push(t_snode **s_a, t_snode **s_b, char *line)
{
	if (!cmp("pa", line, 2))
		pa(s_a, s_b);
	else
		pb(s_a, s_b);
}

void	rotate_stks_bns(t_snode **s_a, t_snode **s_b, char **av, int ac)
{
	char	*cmd;

	cmd = get_next_line(STDIN_FILENO);
	while (cmd)
	{
		if (!cmp("sa", cmd, 2) || !cmp("sb", cmd, 2) || !cmp("ss", cmd, 2))
			moves_swap(s_a, s_b, cmd);
		else if (!cmp("rra", cmd, 3))
			rra(s_a);
		else if (!cmp("rrb", cmd, 3))
			rrb(s_b);
		else if (!cmp("rrr", cmd, 3))
			rrr(s_a, s_b);
		else if (!cmp("ra", cmd, 2) || !cmp("rb", cmd, 2) || !cmp("rr", cmd, 2))
			moves_rotate(s_a, s_b, cmd);
		else if (!cmp("pa", cmd, 2) || !cmp("pb", cmd, 2))
			moves_push(s_a, s_b, cmd);
		else
		{
			free(cmd);
			free_stack_bns(*s_a, av, ac, 1);
		}
		free (cmd);
		cmd = get_next_line(STDIN_FILENO);
	}
}
