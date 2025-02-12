# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carlaugu <carlaugu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/02 12:35:33 by carlaugu          #+#    #+#              #
#    Updated: 2024/11/05 18:31:33 by carlaugu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

NAME = libftprintf.a
SRC = ft_printf.c  ft_char_fd.c  ft_str_fd.c  ft_pointer.c\
      ft_number.c  ft_unsigned_nbr.c  ft_hex_nbr.c
OBJS = ${SRC:.c=.o}

.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

%.o:%.c
	${CC} ${CFLAGS} -c $< -o $@ 

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
