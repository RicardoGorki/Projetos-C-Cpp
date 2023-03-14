#include "so_long.h"

void	h_neg_path(t_vars *s_vars, char **map, int l_pos, int c_pos)
{
	int	max_col;
	int	column;
	int	line;

	line = l_pos;
	column = c_pos;
	max_col = my_strlen(s_vars->map[0]) - 2;
	while (column >= 1 && column < max_col
		&& map[line][column] != '1'
		&& map[line][column] != 'P'
		&& map[line][column] != 'E')
	{
		v_proliferation_path(s_vars, map, line, column);
		if (map[line][column] == '3')
			column--;
		else
			map[line][column--] = '3';
	}
}

void	h_pos_path(t_vars *s_vars, char **map, int l_pos, int c_pos)
{
	int	max_col;
	int	column;
	int	line;

	line = l_pos;
	column = c_pos;
	max_col = my_strlen(s_vars->map[0]) - 2;
	while (column >= 1 && column < max_col
		&& map[line][column] != '1'
		&& map[line][column] != 'P'
		&& map[line][column] != 'E')
	{
		v_proliferation_path(s_vars, map, line, column);
		if (map[line][column] == '3')
			column++;
		else
			map[line][column++] = '3';
	}
}

void	h_proliferation_path(t_vars *s_vars, char **map, int l_pos, int c_pos)
{
	h_neg_path(s_vars, map, l_pos, c_pos);
	h_pos_path(s_vars, map, l_pos, c_pos);
}
