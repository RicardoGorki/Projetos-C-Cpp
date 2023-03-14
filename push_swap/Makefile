SRCS =	src/push_swap.c \
		src/controllers/sorting.c \
		src/controllers/sort_aux.c \
		src/controllers/sort_stack.c \
		src/operations/pushing.c \
		src/operations/reversals.c \
		src/operations/rotations.c \
		src/operations/swaps.c \
		src/exceptions/case_of_errors.c \
		src/exceptions/exceptions_handling.c \
		src/utils/push_pop.c \
		src/utils/lib_aux.c \
		src/utils/utils.c \
		src/utils/utils_msg.c 

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = push_swap

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
