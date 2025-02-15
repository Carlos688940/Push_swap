/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:01:37 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/15 15:35:57 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

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

int	creat_list(t_cmd **list)
{
	char	*cmd;
	t_cmd	*ptr;
	t_cmd	*prev;

	cmd = get_next_line(STDIN_FILENO);
	prev = NULL;
	while (cmd)
	{
		ptr = ft_calloc(1, sizeof(t_cmd));
		if (!ptr)
			return (0);
		ptr->cmd = cmd;
		if (!prev)
			*list = ptr;
		else
			prev->nxt = ptr;
		cmd = get_next_line(STDIN_FILENO);
		prev = ptr;
	}
	return (1);
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
			free_stk_a(*s_a, av, ac, 1);
		ft_bzero(ptr, sizeof(t_snode));
		ptr->val = ft_atoi(av[i]);
		ptr->prev = lst_node;
		ptr->prev->nxt = ptr;
		lst_node = ptr;
	}
}
