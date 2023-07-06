SRCS = push_swap.c stack_init.c swap.c push.c rotate.c reverse_rotate.c tiny_sort.c big_sort.c utils.c sort_case.c utilss.c stack_init_args.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap
CC = gcc
FLAGS = -Wall -Werror -Wextra -g
RM = rm -f
INCS = libft
LIBFT = -Llibft -lft

all: $(NAME)

$(NAME): runlibft $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -I $(INCS) $(LIBFT)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all

runlibft:
	make -C libft
	
norm:
	norminette -R CheckForbiddenSourceHeader $(SRCS) 
	norminette -R CheckDefine $(INCS) push_swap.h

.PHONY: all re clean fclean

