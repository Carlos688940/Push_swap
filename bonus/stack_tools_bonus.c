/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:01:37 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/13 18:30:09 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	define_index_bns(t_snode *stk)
{
	int	i;

	i = -1;
	while (stk)
	{
		stk->ind = ++i;
		stk = stk->nxt;
	}
}

t_snode	*get_last_bns(t_snode *stk)
{
	while (stk)
	{
		if (!stk->nxt)
			break ;
		stk = stk->nxt;
	}
	return (stk);
}

int	check_sort_bns(t_snode *stk_a)
{
	while (stk_a && stk_a->nxt)
	{
		if (stk_a->val > stk_a->nxt->val)
			return (0);
		stk_a = stk_a->nxt;
	}
	return (1);
}

int	cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	stack_a_init_bns(t_snode **s_a, char **av, int ac)
{
	t_snode	*lst_node;
	t_snode	*ptr;
	int		i;

	ptr = malloc(sizeof(t_snode));
	if (!ptr)
		free_splt_bns(av, ac, 1);
	ft_bzero(ptr, sizeof(t_snode));
	ptr->val = ft_atoi(av[0]);
	*s_a = ptr;
	lst_node = *s_a;
	i = 0;
	while (av[++i])
	{
		ptr = malloc(sizeof(t_snode));
		if (!ptr)
			free_stack_bns(*s_a, av, ac, 1);
		ft_bzero(ptr, sizeof(t_snode));
		ptr->val = ft_atoi(av[i]);
		ptr->ind = i;
		ptr->prev = lst_node;
		ptr->prev->nxt = ptr;
		lst_node = ptr;
	}
}
