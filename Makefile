NAME = push_swap

SRCS =  check_args.c ft_rules_1.c \
	ft_rules_2.c \
	ft_rules_3.c \
	ft_rules_4.c \
	index.c \
	push_swap.c \
	radix.c \
	simple.c \
	t_list1.c \
	t_list2.c \
	utils.c

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

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

.PHONY: all clean fclean re
