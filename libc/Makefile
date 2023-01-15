SRCS =		my_isprint.c	\
		my_strlcpy.c	\
		my_memchr.c		\
		my_strlen.c		\
		my_atoi.c		\
		my_memcmp.c		\
		my_strncmp.c	\
		my_bzero.c		\
		my_memcpy.c		\
		my_strnstr.c	\
		my_calloc.c		\
		my_memmove.c	\
		my_strrchr.c	\
		my_isalnum.c	\
		my_memset.c		\
		my_tolower.c	\
		my_isalpha.c	\
		my_strchr.c		\
		my_toupper.c	\
		my_isascii.c	\
		my_strdup.c		\
		my_isdigit.c	\
		my_strlcat.c	\

OBJS = $(SRCS:.c=.o)

CC =	cc

LIBC =	/libc.h

CFLAGS =	-g -Wall -Werror -Wextra -I $(LIBC)

AR = ar rc

RM = rm -f

NAME = libc.a

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		 @$(AR) $(NAME) $(OBJS)
		 @echo "Linked"

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@echo "Objects Deleted"

fclean: clean
	@$(RM) $(NAME)
	@echo "Lib deleted"

re: fclean all

.PHONY: all clean fclean re
