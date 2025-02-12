/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:25:23 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/12 14:25:55 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
		print_error();
}

void	free_stack_bns(t_snode *stk, char **av, int ac, int i)
{
	t_snode	*box;

	while (stk)
	{
		box = stk->nxt;
		free (stk);
		stk = box;
	}
	free_splt(av, ac, i);
}
