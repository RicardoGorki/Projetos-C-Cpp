#include "so_long.h"

void	put_image(t_vars *s_vars, char *relative_path, int lines, int column)
{
	s_vars->relative_path = relative_path;
	s_vars->img = mlx_xpm_file_to_image(s_vars->mlx_ptr, s_vars->relative_path,
			&s_vars->img_width, &s_vars->img_height);
	mlx_put_image_to_window(s_vars->mlx_ptr, s_vars->win_ptr,
		s_vars->img, column * 64, lines * 64);
}

char	**player_location(t_vars *s_vars)
{
	int	lines;
	int	line;
	int	column;

	lines = s_vars->map_size;
	line = 0;
	while (lines)
	{
		column = 0;
		while (s_vars->map[line][column] != '\0')
		{
			while (s_vars->map[line][column] != '\0'
					&& s_vars->map[line][column] != 'P')
				column++;
			if (s_vars->map[line][column] == 'P')
			{
				s_vars->line = line;
				s_vars->column = column;
				return (s_vars->map);
			}
			line++;
		}
		lines--;
	}
	return (NULL);
}
