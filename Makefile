CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MAKE = make -s -C
RM = rm -f

NAME = push_swap

SRCS = src/main.c src/check_input.c src/free_utils.c src/utils.c src/stack_tools.c \
	src/stack_tools2.c src/sort_swap.c src/sort_rotate.c src/sort_reverse_rotate.c\
	src/push_swap.c

OBJS = $(SRCS:.c=.o)
LIBFT = libs/Libft/libft.a

.PHONY: all clean fclean re run

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@if [ -f "$(LIBFT)" ]; then \
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME); \
		echo "$(GREEN)Compilation completed$(RESET)"; \
	else \
		echo "$(RED)Failure compilation!$(RESET)"; \
	fi

$(LIBFT):
	@$(MAKE) libs/Libft

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@$(MAKE) libs/Libft clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) libs/Libft fclean
	@echo "$(GREEN)Everything cleaned!$(RESET)"

re: fclean all

##Colors
GREEN = \033[32m
RED = \033[1;31m
YELLOW = \033[33m
BLUE = \033[34m
RESET = \033[0m
