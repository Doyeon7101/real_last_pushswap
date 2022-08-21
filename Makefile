NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRC_DIR = ./srcs/

SRCS =  ./srcs/algo.c \
		./srcs/operation.c \
		./srcs/oth.c \
		./srcs/parse.c \
		./srcs/push_swap.c \
		./srcs/sort.c \
		./srcs/utils_stack.c \
		./srcs/ft_split.c \
		./srcs/libft.c \
		./srcs/libft2.c 

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(SRCS)
		$(CC) $(CFLAGS) $^ -o $@
clean:
		$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re