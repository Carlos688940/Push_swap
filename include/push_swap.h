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

extern int abc; ///////////

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
	int		val;
	int		ind;
	int		cost;
	struct s_moves	moves;	
	struct s_snode	*tgt;		
	struct s_snode	*nxt;
	struct s_snode	*prev;
}	t_snode;

//----------- Check-input -------------
char	**check_input(char **av, int ac);
//----------- Errors -------------
void	print_error(void);
//----------- Free-Utils -------------
void	free_splt(char **av, int ac, int check);
void	free_stack(t_snode *stk, char **av, int ac, int i);
//----------- Utils -------------
long	ft_atol(char *str);
int	ft_is_signal(char c);
int	get_max(t_snode *stk);
int	get_min(t_snode *stk);
//----------- Stack_tools -------------
void	stack_a_init(t_snode **stk_a, char **av_val, int inpt_cnt);
int	check_sort(t_snode *stk_a);
int	count_nodes(t_snode *stk);
void	sort_three(t_snode **stk);
void	define_index(t_snode *stk); 
t_snode	*get_last(t_snode *stk);
//----------- Sort stack -------------
void	ra(t_snode **stk, int i);
void	rb(t_snode **stk, int i);
void	rr(t_snode **s_a, t_snode **s_b);
void	rra(t_snode **stk, int i);
void	rrb(t_snode **stk, int i);
void	rrr(t_snode **s_a, t_snode **s_b);
void	sa(t_snode **stk, int i);
void	sb(t_snode **stk, int i);
void	ss(t_snode **s_a, t_snode **s_b);
//----------- Push swap -------------
void	ft_push_swap(t_snode **s_a, t_snode **s_b);

#endif