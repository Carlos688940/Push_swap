/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:14:31 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/12 14:27:39 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libs/Libft/libft.h"
# include "../libs/Libft/Get_next_line/get_next_line.h"
# include <limits.h>

typedef struct s_snode
{
	int				val;
	int				ind;
	int				cost;
	struct s_snode	*tgt;	
	struct s_snode	*nxt;
	struct s_snode	*prev;
}	t_snode;

/* -------------------------------------------------------------------------- */
/*                                 Check Input                                */
/* -------------------------------------------------------------------------- */
char	**check_input_bns(char **av, int ac);
/* -------------------------------------------------------------------------- */
/*                                 Free Utils                                 */
/* -------------------------------------------------------------------------- */
void	free_splt_bns(char **av, int ac, int check);
void	free_stack_bns(t_snode *stk, char **av, int ac, int i);
/* -------------------------------------------------------------------------- */
/*                                    Utils                                   */
/* -------------------------------------------------------------------------- */
long	ft_atol_bns(char *str);
int	ft_is_signal_bns(char c);
void	print_error_bns(void);
/* -------------------------------------------------------------------------- */
/*                                 Sort stacks                                */
/* -------------------------------------------------------------------------- */
void	ra(t_snode **stk);
void	rb(t_snode **stk);
void	rr(t_snode **s_a, t_snode **s_b);
void	rra(t_snode **stk);
void	rrb(t_snode **stk);
void	rrr(t_snode **s_a, t_snode **s_b);
void	sa(t_snode **stk);
void	sb(t_snode **stk);
void	ss(t_snode **s_a, t_snode **s_b);
void	pb(t_snode **s_a, t_snode **s_b);
void	pa(t_snode **s_a, t_snode **s_b);

/* -------------------------------------------------------------------------- */
/*                                 stack tools                                */
/* -------------------------------------------------------------------------- */
void	define_index_bns(t_snode *stk);
t_snode	*get_last_bns(t_snode *stk);

#endif
