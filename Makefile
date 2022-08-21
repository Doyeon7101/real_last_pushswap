NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror - Wextra
RM = rm -f

LIB_DIR = ./libft/
SRC_DIR = ./srcs/

S_SRCS =  algo.c \
		operation.c \
		oth.c \
		parse.c \
		push_swap.c \
		sort.c \
		utils_stack.c
O_SRCS = $(S_SRCS:.c=.o)

S_LIBFT = ft_split.c \
		libft.c \
		libft2.c 
O_LIBFT = $(S_LIBFT:.c=.o)

all: $(NAME)

$(NAME): $(O_SRCS) $(O_LIBFT)
		$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(O_LIBFT) $(O_SRCS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re