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

void	ss(t_stk_node **stk_a, t_stk_node **stk_b)
{
	sa(stk_a, 0);
	sb(stk_b, 0);
	ft_putstr_fd("ss\n", 1);
	abc++;
}

void	rr(t_stk_node **stk_a, t_stk_node **stk_b)
{
	ra(stk_a, 0);
	rb(stk_b, 0);
	ft_putstr_fd("rr\n", 1);
	abc++;
}

void	rrr(t_stk_node **stk_a, t_stk_node **stk_b)
{
	rra(stk_a, 0);
	rrb(stk_b, 0);
	ft_putstr_fd("rrr\n", 1);
	abc++;
}