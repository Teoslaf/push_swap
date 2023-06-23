SRCS	= push_swap.c stack_init.c swap.c push.c rotate.c reverse_rotate.c
NAME	= push_swap
CC	= gcc
FLAGS	= -Wall -Werror -Wextra -g
RM	= rm -f
INCS	= libft
LIBFT	= -Llibft -lft

all: ${NAME}

${NAME}: runlibft 
	${CC} ${FLAGS} -o ${NAME} ${SRCS} -I ${INCS} ${LIBFT}

clean:
	${RM} ${NAME}

fclean: clean
	make -C libft fclean

re: fclean all

runlibft:
	make -C libft


.PHONY: all re clean fclean
