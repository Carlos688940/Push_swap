/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:42:21 by carlaugu          #+#    #+#             */
/*   Updated: 2025/01/28 14:03:22 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stk_node *stk)
{
	int	max;
	t_stk_node	*sort;

	(void)sort;
	max = get_max(stk);
	if (stk->value == max)
	{
		sort = ra(stk);
		sort = sa(sort);
	}
	else if (stk->next->value == max)
	{
		rra(stk);
		sa(stk);
	}
	else
		sa(stk);
}

int	count_nodes(t_stk_node *stk)
{
	int	count;

	count = 0;
	while (stk)
	{
		count++;
		stk = stk->next;
	}
	return (count);
}

int	sorted_list(t_stk_node *stk_a)
{
	while (stk_a && stk_a->next)
	{
		if (stk_a->value > stk_a->next->value)
			return (0);
		stk_a = stk_a->next;
	}
	return (1);
}

t_stk_node	*stack_a_init(t_stk_node *stk_a, char **av_val, int inpt_cnt)
{
	t_stk_node	*lst_node;
	t_stk_node	*ptr;
	int	i;

	ptr = malloc(sizeof(t_stk_node));
	if (!ptr)
		free_splt(av_val, inpt_cnt, 1);
	ft_bzero(ptr, sizeof(t_stk_node));
	ptr->value = ft_atoi(av_val[0]);
	stk_a = ptr;
	lst_node = stk_a;
	i = 1;
	while (av_val[i])
	{
		ptr = malloc(sizeof(t_stk_node));
		if (!ptr)
			free_stack(stk_a, av_val, inpt_cnt, 1);
		ft_bzero(ptr, sizeof(t_stk_node));
		ptr->value = ft_atoi(av_val[i]);
		ptr->index = i++;
		ptr->previous = lst_node;
		ptr->previous->next = ptr;
		lst_node = ptr;
	}
	return (stk_a);
}