#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	s_vars;
	char	*title_window;

	if (argc == 2)
	{
		if (check_extension(argv[1]))
			msg_error("Invalid Name");
		title_window = "RGORKI - 42 so_long";
		s_vars.mlx_ptr = mlx_init();
		get_size_map(&s_vars, argv[1]);
		s_vars.win_ptr = mlx_new_window(s_vars.mlx_ptr, HEIGHT * s_vars.height,
				WIDTH * s_vars.width, title_window);
		create_map(&s_vars, argv[1]);
		if (check_validations(&s_vars))
			exit(0);
		mlx_key_hook(s_vars.win_ptr, key_hook_pressed, &s_vars);
		mlx_hook(s_vars.win_ptr, 17, 0, close_press_x, &s_vars);
		mlx_loop(s_vars.mlx_ptr);
	}
	return (0);
}
