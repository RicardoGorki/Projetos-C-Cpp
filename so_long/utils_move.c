#include "so_long.h"

void	display_move(t_vars *s_vars)
{
	my_printf("Moves: %d \n", s_vars->move_count += 1);
}

int	move(t_vars *s_vars, int keycode)
{
	player_location(s_vars);
	if (keycode == 0)
		if (check_move(s_vars, s_vars->map[s_vars->line][s_vars->column - 1]))
			destroy_put_walk(s_vars, keycode);
	if (keycode == 1)
		if (check_move(s_vars, s_vars->map[s_vars->line + 1][s_vars->column]))
			destroy_put_walk(s_vars, keycode);
	if (keycode == 2)
		if (check_move(s_vars, s_vars->map[s_vars->line][s_vars->column + 1]))
			destroy_put_walk(s_vars, keycode);
	if (keycode == 13)
		if (check_move(s_vars, s_vars->map[s_vars->line - 1][s_vars->column]))
			destroy_put_walk(s_vars, keycode);
	return (0);
}

int	check_move(t_vars *s_vars, char c)
{
	if (c == '1')
		return (0);
	if (c == 'C')
	{
		s_vars->get_collection -= 1;
		return (1);
	}
	if (c == '0')
		return (1);
	if (c == 'E' && s_vars->get_collection == 0)
		msg_win_game(s_vars, "Rescue Successful!");
	return (0);
}

void	destroy_put_walk(t_vars *s_vars, int keycode)
{
	s_vars->map[s_vars->line][s_vars->column] = '0';
	mlx_destroy_image(s_vars->mlx_ptr, s_vars->img);
	put_image(s_vars, FLOOR, s_vars->line, s_vars->column);
	mlx_destroy_image(s_vars->mlx_ptr, s_vars->img);
	if (keycode == 0)
		s_vars->column -= 1;
	if (keycode == 1)
		s_vars->line += 1;
	if (keycode == 2)
		s_vars->column += 1;
	if (keycode == 13)
		s_vars->line -= 1;
	put_image(s_vars, CHARACTER, s_vars->line, s_vars->column);
	s_vars->map[s_vars->line][s_vars->column] = 'P';
	display_move(s_vars);
}
