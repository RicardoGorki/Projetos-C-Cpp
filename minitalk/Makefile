PROGS =				\
   	server	\
   	client \

SERVER = server

CLIENT = client

CFLAGS = -Wall -Wextra -Werror

CC = cc

DIR = '../libc/libc.a'

NAME = minitalk

$(NAME):
	make -C ../libc
	${CC} ${CFLAGS}	 server.c ${DIR} -o ${SERVER}
	${CC} ${CFLAGS}  client.c ${DIR} -o ${CLIENT}

RM = rm -f

all: $(NAME)

clean:
	cd ../libc && make clean
	${RM} ${PROGS}

fclean: clean
	cd ../libc && make fclean
	${RM} ${PROGS}

re: fclean all

.PHONY: all clean fclean re
