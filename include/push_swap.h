#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../libs/Libft/libft.h"

typedef struct s_node
{
	int		value;
	int		index;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

#endif