/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:20:50 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/12 14:23:44 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_error_bns(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

long	ft_atol_bns(char *str)
{
	long	result;
	long	i;
	int		sign;

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

int	ft_is_signal_bns(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}
