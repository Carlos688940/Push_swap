/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-25 14:47:12 by carlaugu          #+#    #+#             */
/*   Updated: 2025-01-25 14:47:12 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static int	check_sintax(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && !ft_is_signal(*str))
			return (0);
		str++;
	}
	return (1);
}

static	int	check_int(char *str)
{
	long	i;

	i = ft_atol(str);
	if (i > INT_MAX || i < INT_MIN)
		return (0);
	return (1);
}

static	int	check_duplicate(char **input_values, int input_count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input_values[j])
	{
		i = j;
		while (input_values[j] && input_values[i + 1])
		{
			if (ft_atol(input_values[j]) == ft_atol(input_values [i + 1]))
			{
				free_splt(input_values, input_count);
				print_error();
			}
			i++;
		}
		j++;
	}
	return (0);
}

char	**check_input(char **argv_values, int input_count)
{
	int	i;

	if (input_count == 2)
		argv_values = ft_split(argv_values[0], ' ');
	i = -1;
	while (argv_values[++i])
	{
		if (!check_sintax(argv_values[i]) || !check_int(argv_values[i]))
		{
			free_splt(argv_values, input_count);
			print_error();
		}
	}
	check_duplicate(argv_values, input_count);
	return (argv_values);
}
