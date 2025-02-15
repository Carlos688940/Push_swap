/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:13:56 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/15 11:31:15 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

static void	print_result(t_snode *s_a, t_snode *s_b)
{
	if (check_sort_bns(s_a) && !s_b)
		ft_putstr_fd("OK\n", 1);
	else
	{
		free_stk_b(s_b);
		ft_putstr_fd("KO\n", 2);
	}
}

int	main(int argc, char **argv)
{
	t_snode		*s_a;
	t_snode		*s_b;
	t_cmd		*list;

	s_a = NULL;
	s_b = NULL;
	list = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	argv = check_input_bns(argv + 1, argc);
	if (!creat_list(&list))
		free_list(list, argv, argc, s_a);
	stack_a_init_bns(&s_a, argv, argc);
	if (!rotate_stks_bns(&s_a, &s_b, &list))
	{
		if (s_b)
			free_stk_b(s_b);
		free_list(list, argv, argc, s_a);
	}
	print_result(s_a, s_b);
	free_stk_a(s_a, argv, argc, 0);
}
