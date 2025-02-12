CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MAKE = make -s -C
RM = rm -f

NAME = push_swap
NAME_BNS = checker

SRCS = src/main.c src/check_input.c src/free_utils.c src/utils.c\
       src/stack_tools.c src/stack_tools2.c src/push_swap.c src/push_swap_utils.c src/managing_moves.c\
       src/mov_push.c src/mov_reverse_rotate.c src/mov_rotate.c src/mov_swap.c src/find_mid_nb.c 

BNS_SRC = bonus/main_bonus.c bonus/check_input_bonus.c bonus/free_utils_bonus.c bonus/utils_bonus.c\
	  bonus/mov_push_bonus.c bonus/mov_reverse_rotate_bonus.c bonus/mov_rotate_bonus.c bonus/mov_swap_bonus.c\
	  bonus/stack_tools_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BNS = $(BNS_SRC:.c=.o)
LIBFT = libs/Libft/libft.a
GNL = libs/Libft/Get_next_line/get_next_line.a

.PHONY: all clean fclean re run

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@if [ -f "$(LIBFT)" ]; then \
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME); \
		echo "$(GREEN)Compilation completed$(RESET)"; \
	else \
		echo "$(RED)Failure compilation!$(RESET)"; \
	fi


test:
	valgrind --leak-check=full --show-leak-kinds=all ./push_swap $$ARG  && ./push_swap $$ARG | wc -l && ./push_swap $$ARG | ./checker_linux $$ARG

bonus: $(NAME_BNS)


$(NAME_BNS): $(LIBFT) $(GNL) $(OBJS_BNS)
	@if [ -f "$(LIBFT)" ] && [ -f "$(GNL)" ]; then \
		$(CC) $(CFLAGS) $(OBJS_BNS) $(LIBFT) $(GNL) -o $(NAME_BNS); \
		echo "$(GREEN)Compilation completed$(RESET)"; \
	else \
		echo "$(RED)Failure compilation!$(RESET)"; \
	fi

$(LIBFT):
	@$(MAKE) libs/Libft

$(GNL):
	@$(MAKE) libs/Libft/Get_next_line


%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@$(MAKE) libs/Libft clean

clean_bonus:
	@$(RM) $(OBJS_BNS)
	@$(MAKE) libs/Libft clean
	@$(MAKE) libs/Libft/Get_next_line clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) libs/Libft fclean
	@echo "$(GREEN)Everything cleaned!$(RESET)"

fclean_bonus: clean_bonus
	@$(RM) $(NAME_BNS)
	@$(MAKE) libs/Libft fclean
	@$(MAKE) libs/Libft/Get_next_line fclean
	@echo "$(GREEN)Everything cleaned!$(RESET)"

re: fclean all

##Colors
GREEN = \033[32m
RED = \033[1;31m
YELLOW = \033[33m
BLUE = \033[34m
RESET = \033[0m
