SRCS =		megaphone.cpp	\

OBJS =		$(SRCS:.cpp=.o)

CPP =		c++

CFLAGS =	-Wall -Werror -Wextra -std=c++98

RM =		rm -f

NAME =		megaphone

.c.o:
			@$(CPP) $(CFLAGS) -c $< -o $(<:.cpp=.o)

all:		$(NAME)

$(NAME):	$(SRCS)
			$(CPP) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
			@$(RM) $(OBJS)
			@echo "Objects Deleted"

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re
