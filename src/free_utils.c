/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-25 18:02:46 by carlaugu          #+#    #+#             */
/*   Updated: 2025-01-25 18:02:46 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "../include/push_swap.h"

void	free_splt(char **av, int ac, int check)
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

void	free_stack(t_stk_node *stk, char **av_val, int inpt_cnt, int i)
{
	t_stk_node	*box;

	while (stk)
	{
		box = stk->next;
		free (stk);
		stk = box;
	}
	free_splt(av_val, inpt_cnt, i);
}