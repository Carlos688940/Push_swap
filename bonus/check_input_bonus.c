/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:11:07 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/12 14:28:23 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static int	check_sintax(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && !ft_is_signal_bns(*str))
			return (0);
		str++;
	}
	return (1);
}

static	int	check_int(char *str)
{
	long	i;

	i = ft_atol_bns(str);
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
			if (ft_atol_bns(av[j]) == ft_atol_bns(av [i + 1]))
				free_splt_bns(av, ac, 1);
			i++;
		}
		j++;
	}
	return (0);
}

char	**check_input_bns(char **av, int ac)
{
	int	i;

	if (ac == 2)
		av = ft_split(av[0], ' ');
	i = -1;
	while (av[++i])
	{
		if (!check_sintax(av[i]) || !check_int(av[i]))
			free_splt_bns(av, ac, 1);
	}
	check_duplicate(av, ac);
	return (av);
}
