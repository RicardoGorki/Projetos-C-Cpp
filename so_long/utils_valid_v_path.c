#include "so_long.h"

void	v_neg_path(t_vars *s_vars, char **map, int l_pos, int c_pos)
{
	int	max_line;
	int	line;
	int	column;

	line = l_pos;
	column = c_pos;
	max_line = s_vars->map_size - 1;
	while (line >= 1 && line < max_line
		&& map[line][column] != '1'
		&& map[line][column] != 'P'
		&& map[line][column] != 'E')
	{
		if (map[line][column] == '3')
			line--;
		else
		{
			map[line--][column] = '3';
			h_proliferation_path(s_vars, map, line, column);
		}
	}
}

void	v_pos_path(t_vars *s_vars, char **map, int l_pos, int c_pos)
{
	int	max_line;
	int	line;
	int	column;

	line = l_pos;
	column = c_pos;
	max_line = s_vars->map_size - 1;
	while (line >= 1 && line < max_line
		&& map[line][column] != '1'
		&& map[line][column] != 'P'
		&& map[line][column] != 'E')
	{
		if (map[line][column] == '3')
		{
			line++;
			h_proliferation_path(s_vars, map, line, column);
		}
		else
		{
			map[line++][column] = '3';
			h_proliferation_path(s_vars, map, line, column);
		}
	}
}

void	v_proliferation_path(t_vars *s_vars, char **map, int l_pos, int c_pos)
{
	v_neg_path(s_vars, map, l_pos, c_pos);
	v_pos_path(s_vars, map, l_pos, c_pos);
}
