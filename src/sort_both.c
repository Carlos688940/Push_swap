/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-30 21:16:25 by carlaugu          #+#    #+#             */
/*   Updated: 2025-01-30 21:16:25 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ss(t_stk_node *stk_a, t_stk_node *stk_b)
{
	sa(stk_a);
	sb(stk_b);
	ft_putstr_fd("ss\n", 1);
}

void	rr(t_stk_node *stk_a, t_stk_node *stk_b)
{
	ra(stk_a);
	rb(stk_b);
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_stk_node *stk_a, t_stk_node *stk_b)
{
	rra(stk_a);
	rrb(stk_b);
	ft_putstr_fd("rrr\n", 1);
}