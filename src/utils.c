/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:04:29 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/06 14:38:18 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	ft_round(float i)
{
	return (i + 0.5);
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