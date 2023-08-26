SRCS =		main.cpp	\

HPPS =		iter.hpp	\

OBJS =		$(SRCS:.cpp=.o)

CPP =		c++

CFLAGS =	-Wall -Werror -Wextra -std=c++98

RM =		rm -f

NAME =		iter

RED			=		\033[0;31m
GREEN		=		\033[0;32m
RESET		=		\033[0m

.cpp.o:
			@$(CPP) $(CFLAGS) -c $< -o $@
			@echo "$(GREEN)objects created$(RESET)"

all:		$(NAME)

$(NAME):	$(OBJS) $(HPPS)
			@$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "$(GREEN)$(NAME) created$(RESET)"

clean:
			@echo "$(RED)objects deleted$(RESET)"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(RED)$(NAME) deleted$(RESET)"

re:			fclean all

.PHONY:		all clean fclean re
