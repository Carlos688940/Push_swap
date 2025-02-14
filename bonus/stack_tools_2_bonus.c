/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:46:19 by carlaugu          #+#    #+#             */
/*   Updated: 2025/02/13 18:46:11 by carlaugu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	creat_list(t_cmd **list)
{
	char	*cmd;
	t_cmd	*ptr;
	t_cmd	*prev;

	cmd = get_next_line(STDIN_FILENO);
	prev = NULL;
	while (cmd)
	{
		ptr = ft_calloc(1, sizeof(t_cmd));
		if (!ptr)
			return (0);
		ptr->cmd = cmd;
		if (!prev)
			*list = ptr;
		else
			prev->nxt = ptr;
		cmd = get_next_line(STDIN_FILENO);
		prev = ptr;
	}
	return (1);
}
