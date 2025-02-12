/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:42:21 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/12 11:38:03 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	define_index(t_snode *stk)
{
	int	i;

	i = -1;
	while (stk)
	{
		stk->ind = ++i;
		stk = stk->nxt;
	}
}

void	sort_three(t_snode **stk)
{
	int	max;

	max = get_max(*stk)->val;
	if ((*stk)->val == max)
	{
		ra(stk);
		if ((*stk)-> val > (*stk)->nxt->val)
			sa(stk);
	}
	else if ((*stk)->nxt->val == max)
	{
		rra(stk);
		if ((*stk)->val > (*stk)->nxt->val)
			sa(stk);
	}
	else
	{
		if ((*stk)->val > (*stk)->nxt->val)
			sa(stk);
	}
}

int	count_nodes(t_snode *stk)
{
	int	count;

	count = 0;
	while (stk)
	{
		count++;
		stk = stk->nxt;
	}
	return (count);
}

int	check_sort(t_snode *stk_a)
{
	while (stk_a && stk_a->nxt)
	{
		if (stk_a->val > stk_a->nxt->val)
			return (0);
		stk_a = stk_a->nxt;
	}
	return (1);
}

void	stack_a_init(t_snode **s_a, char **av, int ac)
{
	t_snode	*lst_node;
	t_snode	*ptr;
	int		i;

	ptr = malloc(sizeof(t_snode));
	if (!ptr)
		free_splt(av, ac, 1);
	ft_bzero(ptr, sizeof(t_snode));
	ptr->val = ft_atoi(av[0]);
	*s_a = ptr;
	lst_node = *s_a;
	i = 0;
	while (av[++i])
	{
		ptr = malloc(sizeof(t_snode));
		if (!ptr)
			free_stack(*s_a, av, ac, 1);
		ft_bzero(ptr, sizeof(t_snode));
		ptr->val = ft_atoi(av[i]);
		ptr->ind = i;
		ptr->prev = lst_node;
		ptr->prev->nxt = ptr;
		lst_node = ptr;
	}
}
