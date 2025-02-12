/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:08:10 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/12 14:21:54 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/Libft/libft.h"
# include <limits.h>

typedef struct s_moves
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	rr;
	int	rrr;
}	t_moves;

typedef struct s_snode
{
	int				val;
	int				ind;
	int				cost;
	struct s_snode	*tgt;	
	struct s_snode	*nxt;
	struct s_snode	*prev;
}	t_snode;

typedef struct s_info
{
	int		max_ind;
	int		mid_ind;
	int		count;
	t_snode	*min;
	t_snode	*max;
	t_snode	*mid_nb;
}	t_info;

typedef struct s_lower
{
	t_snode		*node;
	t_moves		mov;
}	t_lower;

/* ---------------------------------------------------------------------*/
/*                                 Check-input                          */
/* ---------------------------------------------------------------------*/
char	**check_input(char **av, int ac);
/* ----------------------------------------------------------------------*/
/*                                   Errors                              */
/* ----------------------------------------------------------------------*/
void	print_error(void);
/* -----------------------------------------------------------------------*/
/*                                 Free-Utils                             */
/* -----------------------------------------------------------------------*/
void	free_splt(char **av, int ac, int check);
void	free_stack(t_snode *stk, char **av, int ac, int i);
/* ------------------------------------------------------------------------*/
/*                                    Utils                                */
/* ------------------------------------------------------------------------*/
int		ft_is_signal(char c);
long	ft_atol(char *str);
/* ------------------------------------------------------------------------*/
/*                                 Stack_tools                             */
/* ------------------------------------------------------------------------*/
int		check_sort(t_snode *stk_a);
int		count_nodes(t_snode *stk);
void	stack_a_init(t_snode **stk_a, char **av_val, int inpt_cnt);
void	sort_three(t_snode **stk);
void	define_index(t_snode *stk);
void	reset_info_a(t_snode *s_a, t_info *info);
t_snode	*get_last(t_snode *stk);
t_snode	*get_max(t_snode *stk);
t_snode	*get_min(t_snode *stk);
/* -------------------------------------------------------------------------- */
/*                                 Sort stack                                 */
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
/*                                  Push swap                                 */
/* -------------------------------------------------------------------------- */
void	ft_push_swap(t_snode **s_a, t_snode **s_b);
void	find_mid_n(t_snode *s_a, t_info *info, int *mid_nb);
void	find_target(t_snode *node, t_snode *s_a);
void	push_mid_nb(t_snode **s_a, t_snode **s_b, t_info *inf_a);
/* -------------------------------------------------------------------------- */
/*                                    Moves                                   */
/* -------------------------------------------------------------------------- */
void	rotate_stks(t_snode **s_a, t_snode **s_b, t_moves *moves);
void	find_a_cost(t_snode *s_a, t_info *inf_a, t_lower *lower);
void	find_b_cost(t_snode *node, t_snode **s_b, t_info *inf_a, \
						t_lower *lower);

#endif
