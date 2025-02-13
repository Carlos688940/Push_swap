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

static	void	check_list(t_cmd **list, t_cmd *ptr)
{
	if (!*list)
		*list = ptr;
}

void	creat_list(t_cmd **list)
{
	char	*cmd;
	t_cmd	*ptr;
	t_cmd	*prev;

	cmd = get_next_line(STDIN_FILENO);
	ptr = NULL;
	prev = NULL;
	while (cmd)
	{
		while (ptr)
		{
			prev = ptr;
			ptr = ptr->nxt;
		}
		if (!ptr)
		{
			ptr = ft_calloc(1, sizeof(t_cmd));
			ptr->cmd = cmd;
			if (prev)
				prev->nxt = ptr;
			check_list(list, ptr);
		}
		cmd = get_next_line(STDIN_FILENO);
		ptr = *list;
	}
}
