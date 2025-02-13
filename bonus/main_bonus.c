/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:13:56 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/13 18:38:36 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_snode		*s_a;
	t_snode		*s_b;
	t_cmd		*list;

	s_a = NULL;
	s_b = NULL;
	list = NULL;
	if (argc == 1 || !argv[1][0])
		return (1);
	argv = check_input_bns(argv + 1, argc);
	stack_a_init_bns(&s_a, argv, argc);
	creat_list(&list);
	if (rotate_stks_bns(&s_a, &s_b, list))
		free_stack_bns(s_a, argv, argc, 1);
	if (check_sort_bns(s_a) && !s_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 2);
	free_stack_bns(s_a, argv, argc, 0);
}
