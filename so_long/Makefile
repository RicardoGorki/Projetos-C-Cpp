SRCS = main.c \
	   utils_checks.c \
	   utils_key_hook.c \
	   utils_map.c \
	   utils_move.c \
	   utils_msg.c \
	   utils_render_map.c \
	   utils_valid_h_path.c \
	   utils_valid_map.c \
	   utils_valid_v_path.c \
	   utils_validation.c \
	   utils_valid_size_map.c \

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

LIBFT = libft/libft.a

MLX = mlx/libmlx.a

RM = rm -f

NAME = so_long

$(NAME): $(SRCS)
	make -C libft
	make -C mlx
	$(CC) $(CFLAGS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	cd libft && make clean
	cd mlx && make clean
	$(RM)

fclean: clean
	cd libft && make fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
