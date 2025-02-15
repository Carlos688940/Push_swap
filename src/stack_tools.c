/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:42:21 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/15 11:12:45 by carlaugu         ###   ########.fr       */
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

	i = -1;
	lst_node = 0;
	ptr = 0;
	while (av[++i])
	{
		ptr = malloc(sizeof(t_snode));
		if (!ptr)
			free_stack(*s_a, av, ac, 1);
		if (!*s_a)
			*s_a = ptr;
		ft_bzero(ptr, sizeof(t_snode));
		ptr->val = ft_atoi(av[i]);
		ptr->ind = i;
		if (lst_node)
		{
			ptr->prev = lst_node;
			ptr->prev->nxt = ptr;
		}
		lst_node = ptr;
	}
}
