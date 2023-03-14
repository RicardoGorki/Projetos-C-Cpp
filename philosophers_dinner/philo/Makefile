SRCS =	src/philosofers.c \
		src/controllers/table.c \
		src/controllers/actions.c \
		src/controllers/create_threads.c \
		src/controllers/create_philos_forks.c \
		src/controllers/populates.c \
		src/utils/lib_aux.c \
		src/utils/push.c \
		src/utils/pop.c \
		src/utils/utils_msg.c \
		src/utils/utils.c \

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

THREADS =	-pthread

RM = rm -f

NAME = philo

$(NAME): $(SRCS)
	$(CC) $(THREADS) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
