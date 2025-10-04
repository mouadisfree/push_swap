NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ./c/main.c \
	   ./c/ft_split.c \
	   ./c/invalid_input.c \
	   ./c/nodes.c \
	   ./c/sorting_2-20.c \
	   ./c/sorting_100.c \
	   ./c/sorting_500.c \
	   ./c/sorting_tools.c \
	   ./c/stack_a.c \
	   ./c/stack_b.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
