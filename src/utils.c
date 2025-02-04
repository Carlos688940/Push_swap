/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-25 18:04:29 by carlaugu          #+#    #+#             */
/*   Updated: 2025-01-25 18:04:29 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	get_min(t_snode *stk)
{
	int	min;

	min = INT_MAX;
	while (stk)
	{
		if (stk->val < min)
			min = stk->val;
		stk = stk->nxt;
	}
	return (min);
}

int	get_max(t_snode *stk)
{
	int	max;

	max = INT_MIN;
	while (stk)
	{
		if (stk->val > max)
			max = stk->val;
		stk = stk->nxt;
	}
	return (max);
}

long	ft_atol(char *str)
{
	long	result;
	long	i;
	int	sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}

int	ft_is_signal(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}