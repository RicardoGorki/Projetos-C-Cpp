#include "so_long.h"

void	msg_error(char *msg)
{
	my_printf("\nError\n%s\n", msg);
	exit(0);
}

void	msg_error_map(t_vars *s_vars, char *msg)
{
	int	lines;

	lines = s_vars->map_size - 1;
	my_printf("\nError\n%s\n", msg);
	free_map(s_vars->map, lines);
	free(s_vars->map_arg);
	mlx_destroy_image(s_vars->mlx_ptr, s_vars->img);
	mlx_destroy_window(s_vars->mlx_ptr, s_vars->win_ptr);
	exit(0);
}

void	msg_close_game(t_vars *s_vars, char *msg)
{
	int	lines;

	lines = s_vars->map_size - 1;
	my_printf("\n\n%s\n", msg);
	free_map(s_vars->map, lines);
	free_map(s_vars->map_temp, lines);
	free(s_vars->map_arg);
	mlx_destroy_image(s_vars->mlx_ptr, s_vars->img);
	mlx_destroy_window(s_vars->mlx_ptr, s_vars->win_ptr);
	exit(0);
}

void	msg_win_game(t_vars *s_vars, char *msg)
{
	int	lines;

	lines = s_vars->map_size - 1;
	my_printf("\n\n%s\n", msg);
	free_map(s_vars->map, lines);
	free_map(s_vars->map_temp, lines);
	free(s_vars->map_arg);
	mlx_destroy_image(s_vars->mlx_ptr, s_vars->img);
	mlx_destroy_window(s_vars->mlx_ptr, s_vars->win_ptr);
	exit(0);
}
