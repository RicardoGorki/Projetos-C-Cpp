#include "so_long.h"

int	close_press_x(t_vars *s_vars)
{
	msg_close_game(s_vars, "Closing...");
	return (0);
}

int	key_hook_pressed(int keycode, t_vars *s_vars)
{
	if (keycode == 0)
		move(s_vars, 0);
	if (keycode == 1)
		move(s_vars, 1);
	if (keycode == 2)
		move(s_vars, 2);
	if (keycode == 13)
		move(s_vars, 13);
	if (keycode == 53)
	{
		msg_close_game(s_vars, "Closing...");
	}
	return (0);
}
