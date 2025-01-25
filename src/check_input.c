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

static void	print_error()
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static int	check_sintax(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && !ft_is_signal(*str))
			return(0);
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

static	int	check_duplicate(char **av, int ac)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[j])
	{
		i = j;
		while (av[j] && av[i + 1])
		{
			if (ft_atol(av[j]) == ft_atol(av [i + 1]))
			{
				free_splt(av, ac);
				return (1);
			}
			i++;			
		}
		j++;
	}
	return (0);
}

char	**check_input(char **av, int ac)
{
	int	i;

	if (ac == 2)
		av = ft_split(av[0], ' ');
	i = -1;
	while (av[++i])
	{
		if (!check_sintax(av[i]) || !check_int(av[i]))
		{
			free_splt(av, ac);
			print_error();
		}
	}
	check_duplicate(av, ac);
	return (av);
}