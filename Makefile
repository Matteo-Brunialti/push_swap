NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC		=	push_swap.c				\
			rotate.c				\
			swap.c					\
			push.c					\
			reverse_rotate.c 		\
			doubly_linked_list.c	\
			validate_args.c			\
			algorithm.c				\
			utils_algorithm.c		

OBJ		= $(SRC:.c=.o)

HEADER	= push_swap.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re