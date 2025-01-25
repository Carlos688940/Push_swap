/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-25 12:14:13 by carlaugu          #+#    #+#             */
/*   Updated: 2025-01-25 12:14:13 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	if (argc == 1 || !argv[1][0])
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	// stack_init(argv, )
	return (0);
}