/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:08:10 by carlaugu          #+#    #+#             */
/*   Updated: 2025/01/28 14:18:00 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../libs/Libft/libft.h"
# include <limits.h>

typedef struct s_stk_node
{
	int		value;
	int		index;
	struct s_stk_node	*next;
	struct s_stk_node	*previous;
}	t_stk_node;

//----------- Check-input -------------
char	**check_input(char **av, int ac);
//----------- Errors -------------
void	print_error(void);
//----------- Free-Utils -------------
void	free_splt(char **av, int ac, int check);
void	free_stack(t_stk_node *stk, char **av_val, int inpt_cnt, int i);
//----------- Utils -------------
long	ft_atol(char *str);
int	ft_is_signal(char c);
int	get_max(t_stk_node *stk);
//----------- Stack_tools -------------
t_stk_node	*stack_a_init(t_stk_node *stk_a, char **av_val, int inpt_cnt);
int	check_sort(t_stk_node *stk_a);
int	count_nodes(t_stk_node *stk);
t_stk_node	*sort_three(t_stk_node *stk);
///////////////////////////// void	define_index(t_stk_node *stk); ////////////////
t_stk_node	*get_last(t_stk_node *stk);
//----------- Sort stack -------------
t_stk_node	*sa(t_stk_node *stk);
t_stk_node	*rra(t_stk_node *stk);
t_stk_node	*ra(t_stk_node *stk);

#endif