/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:14:31 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/15 15:51:37 by carlaugu         ###   ########.fr       */
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
	struct s_snode	*nxt;
	struct s_snode	*prev;
}	t_snode;

typedef struct s_cmd
{
	char			*cmd;
	struct s_cmd	*nxt;
}	t_cmd;

/* -------------------------------------------------------------------------- */
/*                                 Check Input                                */
/* -------------------------------------------------------------------------- */
char	**check_input_bns(char **av, int ac);
/* -------------------------------------------------------------------------- */
/*                                 Free Utils                                 */
/* -------------------------------------------------------------------------- */
void	free_splt_bns(char **av, int ac, int check);
void	free_stk_a(t_snode *stk, char **av, int ac, int i);
void	free_list(t_cmd *list, char **av, int ac, t_snode *s_a);
void	free_stk_b(t_snode *s_b);
/* -------------------------------------------------------------------------- */
/*                                    Utils                                   */
/* -------------------------------------------------------------------------- */
long	ft_atol_bns(char *str);
void	print_error_bns(void);
int		ft_is_signal_bns(char c);
/* -------------------------------------------------------------------------- */
/*                                 Stack Moves                                */
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
/*                                 Stack Tools                                */
/* -------------------------------------------------------------------------- */
void	stack_a_init_bns(t_snode **s_a, char **av, int ac);
t_snode	*get_last_bns(t_snode *stk);
int		creat_list(t_cmd **list);
int		check_sort_bns(t_snode *stk_a);
int		cmp(char *s1, char *s2);
/* -------------------------------------------------------------------------- */
/*                                Manage Moves                                */
/* -------------------------------------------------------------------------- */
int		rotate_stks_bns(t_snode **s_a, t_snode **s_b, t_cmd **list);

#endif
