SRCS = my_printf.c my_putchar.c my_putstr.c my_pointer.c my_count_int.c my_putnbr_int.c my_putnbr_unsigned.c my_count_hex.c my_count_pointer.c my_count_unsigned.c my_putnbr_hex_lower.c my_putnbr_hex_upper.c

CFLAGS = -Wall -Wextra -Werror

CC = cc

NAME = my_printf

RM = rm -f

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re

CLEAR = clear
MAIN = main.c
OUT = ./a.out
run: $(SRCS)
	$(CLEAR); $(CC) $(CFLAGS) $(SRCS) $(MAIN)
