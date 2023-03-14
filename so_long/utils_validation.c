#include "so_long.h"

void	neg_contamination(t_vars *s_vars, char **map, int l_pos, int c_pos)
{
	int	max_line;
	int	line;
	int	column;
	int	max_col;

	max_line = s_vars->map_size - 1;
	line = l_pos;
	column = c_pos;
	max_col = my_strlen(map[0]) - 2;
	while (max_line > 0 && line >= 1)
	{
		while (column > 0 && column < max_col && line >= 1
			&& map[line][column] != '\0'
			&& map[line][column] != '\n')
		{
			if (map[line][column] == '3' || map[line - 1][column] == '3'
				|| map[line + 1][column] == '3')
				h_proliferation_path(s_vars, map, line, column);
				column--;
		}
		line--;
		max_line--;
		column = c_pos;
	}
}

void	pos_contamination(t_vars *s_vars, char **map, int l_pos, int c_pos)
{
	int	max_line;
	int	line;
	int	column;
	int	max_col;

	max_line = s_vars->map_size - 1;
	line = l_pos;
	column = c_pos;
	max_col = my_strlen(map[0]) - 2;
	while (line < max_line)
	{
		while (column > 0 && column < max_col
			&& line < max_line
			&& map[line][column] != '\0'
			&& map[line][column] != '\n')
		{
			if (map[line][column] == '3' || map[line - 1][column] == '3'
				|| map[line + 1][column] == '3')
				h_proliferation_path(s_vars, map, line, column);
			column++;
		}
		line++;
		column = c_pos;
	}
}

void	contamination_path(t_vars *s_vars, char **map, int l_pos, int c_pos)
{
	int	max_line;
	int	line;
	int	column;
	int	max_col;

	max_line = s_vars->map_size;
	line = l_pos;
	column = c_pos;
	max_col = my_strlen(map[0]) - 2;
	while (max_line > 0)
	{
		if (map[line][column] == '3'
				|| map[line - 1][column] == '3'
				|| map[line + 1][column] == '3')
		{
			neg_contamination(s_vars, map, l_pos, c_pos);
			pos_contamination(s_vars, map, l_pos, c_pos);
		}
		max_line--;
	}
}

int	free_map(char **map, int line)
{
	while (map[line] != NULL && line != 0)
		free(map[line--]);
	return (0);
}

void	find_valid_path(t_vars *s_vars, char c)
{
	int		max_line;
	int		line;
	int		column;
	char	**map;

	max_line = s_vars->map_size;
	line = 0;
	map = create_temp_map(s_vars);
	while (max_line > 0)
	{
		column = 0;
		while (map[line][column] != '\0' && map[line][column] != '\n')
		{
			if (map[line][column] == c)
			{
				map[line][column] = '3';
				contamination_path(s_vars, map, line, column);
				map = check_content(s_vars, map, max_line);
			}
			column++;
		}
		line++;
		max_line--;
	}
}
