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

static	int	check_duplicate(char **av_val, int inpt_cnt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av_val[j])
	{
		i = j;
		while (av_val[j] && av_val[i + 1])
		{
			if (ft_atol(av_val[j]) == ft_atol(av_val [i + 1]))
				free_splt(av_val, inpt_cnt, 1);
			i++;
		}
		j++;
	}
	return (0);
}

char	**check_input(char **av_val, int inpt_cnt)
{
	int	i;

	if (inpt_cnt == 2)
		av_val = ft_split(av_val[0], ' ');
	i = -1;
	while (av_val[++i])
	{
		if (!check_sintax(av_val[i]) || !check_int(av_val[i]))
			free_splt(av_val, inpt_cnt, 1);
	}
	check_duplicate(av_val, inpt_cnt);
	return (av_val);
}
