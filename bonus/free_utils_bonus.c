/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:25:23 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/15 11:29:04 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	free_stk_b(t_snode *s_b)
{
	t_snode		*box;

	while (s_b)
	{
		box = s_b->nxt;
		free(s_b);
		s_b = box;
	}
}

void	free_splt_bns(char **av, int ac, int check)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[i])
			free(av[i++]);
		free (av);
	}
	if (check)
		print_error_bns();
}

void	free_stk_a(t_snode *stk, char **av, int ac, int i)
{
	t_snode	*box;

	while (stk)
	{
		box = stk->nxt;
		free (stk);
		stk = box;
	}
	free_splt_bns(av, ac, i);
}

void	free_list(t_cmd *list, char **av, int ac, t_snode *s_a)
{
	t_cmd	*box;

	while (list)
	{
		box = list->nxt;
		free(list->cmd);
		free(list);
		list = box;
	}
	if (s_a)
		free_stk_a(s_a, av, ac, 1);
	else
		free_splt_bns(av, ac, 1);
}
