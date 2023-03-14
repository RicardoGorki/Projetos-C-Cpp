SRCS =	get_next_line.c \
		get_next_line_utils.c \

CFLAGS = -g -Wall -Wextra -Werror

CC = cc

NAME = get_next_line

RM = rm -f

$(NAME): $(SRCS)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(NAME)

run:
	$(CC) $(CFLAGS) $(SRCS) main.c -o $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
