/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-25 18:08:10 by carlaugu          #+#    #+#             */
/*   Updated: 2025-01-25 18:08:10 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../libs/Libft/libft.h"
# include <limits.h>

typedef struct s_node
{
	int		value;
	int		index;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

//----------- Check-input -------------
char	**check_input(char **av, int ac);

//----------- Free-Utils -------------
void	free_splt(char **av, int ac);

//----------- Utils -------------
long	ft_atol(char *str);
int	ft_is_signal(char c);

#endif