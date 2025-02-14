/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:11:07 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/13 14:41:40 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static int	check_sintax_bns(char *str)
{
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str) && !ft_is_signal_bns(*str))
			return (0);
		if (ft_is_signal_bns(*str) && !ft_isdigit(*(str + 1)))
			return (0);
		str++;
	}
	return (1);
}

static	int	check_int_bns(char *str)
{
	long	i;

	i = ft_atol_bns(str);
	if (i > INT_MAX || i < INT_MIN)
		return (0);
	return (1);
}

static	int	check_duplicate_bns(char **av, int ac)
{
	int	i;
	int	j;

	j = 0;
	while (av[j])
	{
		i = j + 1;
		while (av[j] && av[i])
		{
			if (ft_atol_bns(av[j]) == ft_atol_bns(av[i]))
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
	{
		av = ft_split(av[0], ' ');
		if (!*av)
			free_splt_bns(av, ac, 1);
	}
	i = -1;
	while (av[++i])
	{
		if (!check_sintax_bns(av[i]) || !check_int_bns(av[i]))
			free_splt_bns(av, ac, 1);
	}
	check_duplicate_bns(av, ac);
	return (av);
}
