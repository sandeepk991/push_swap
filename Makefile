# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skaur <skaur@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/23 11:29:29 by skaur             #+#    #+#              #
#    Updated: 2023/06/23 11:30:50 by skaur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =  ft_rules_1.c \
	ft_rules_2.c \
	ft_rules_3.c \
	ft_rules_4.c \
	index.c \
	push_swap.c \
	radix.c \
	simple.c \
	t_list1.c \
	t_list2.c \
	utils.c \
	utils2.c \
	check_args.c

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g
CHECKER = ./push_swap $(ARG) | ./checker_linux $(ARG)
RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

clean: 
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}
fclean: clean
	@${RM} ${NAME}

re: fclean all

size ?= 5

test: $(NAME)
		@$(eval ARG = $(shell seq -5000 5000 | shuf -n $(size)))
		@echo "Checker result: "
		@$(CHECKER)
		@echo "Instructions count: "
		@./push_swap $(ARG) | wc -l
		@echo "Valgrind result: "
		@if valgrind ./push_swap $(ARG) 2>&1 | grep -q "All heap blocks were freed"; then echo "OK"; else echo -e "KO"; fi

.PHONY: all clean fclean re
