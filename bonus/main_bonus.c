/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:13:56 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/12 14:19:25 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	stack_a_init(t_snode **s_a, char **av, int ac)
{
	t_snode	*lst_node;
	t_snode	*ptr;
	int		i;

	ptr = malloc(sizeof(t_snode));
	if (!ptr)
		free_splt_bns(av, ac, 1);
	ft_bzero(ptr, sizeof(t_snode));
	ptr->val = ft_atoi(av[0]);
	*s_a = ptr;
	lst_node = *s_a;
	i = 0;
	while (av[++i])
	{
		ptr = malloc(sizeof(t_snode));
		if (!ptr)
			free_stack_bns(*s_a, av, ac, 1);
		ft_bzero(ptr, sizeof(t_snode));
		ptr->val = ft_atoi(av[i]);
		ptr->ind = i;
		ptr->prev = lst_node;
		ptr->prev->nxt = ptr;
		lst_node = ptr;
	}
}


int	main(int argc, char **argv)
{
	t_snode *s_a;
	t_snode *s_b;
	char	*line;

	(void)s_b;
	(void)line;
	s_a = NULL;
	s_b = NULL;
	if (argc == 1 || !argv[1][0])
		return (1);
	argv = check_input_bns(argv + 1, argc);
	stack_a_init(&s_a, argv, argc);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (!ft_strncmp("sa", line, 2))
			sa(&s_a);
		else if (!ft_strncmp("sb", line, 2))
			sb(&s_a);
		else if (!ft_strncmp("ss", line, 2))
			ss(&s_a, &s_b);
		else if (!ft_strncmp("ra", line, 2))
			ra(&s_a);
		else if (!ft_strncmp("rb", line, 2))
			rb(&s_b);
		else if (!ft_strncmp("rr", line, 2))
			rr(&s_a, &s_b);
		else if (!ft_strncmp("rra", line, 3))
			rra(&s_a);
		else if (!ft_strncmp("rrb", line, 3))
			rrb(&s_b);
		else if (!ft_strncmp("rrr", line, 3))
			rrr(&s_a, &s_b);
		line = get_next_line(STDIN_FILENO);
	}
	ft_putstr_fd("pla", 1);
}