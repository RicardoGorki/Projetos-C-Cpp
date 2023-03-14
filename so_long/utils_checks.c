#include "so_long.h"

int	get_position(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n' && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (0);
}

int	check_blocks(t_vars *s_vars, char c)
{
	int	lines;
	int	line;
	int	column;

	lines = s_vars->map_size;
	line = 0;
	column = 0;
	while (lines > 0)
	{
		column = get_position(s_vars->map[line], c);
		if (s_vars->map[line][column] == c)
			if (s_vars->map[line][column - 1] == '1'
				&& s_vars->map[line + 1][column] == '1'
					&& s_vars->map[line][column + 1] == '1'
					&& s_vars->map[line - 1][column] == '1')
				return (1);
		line++;
		lines--;
	}
	return (0);
}

int	check_valid_player(t_vars *s_vars, char **map)
{
	int	line;
	int	column;
	int	max_line;

	line = 0;
	column = 0;
	max_line = s_vars->map_size - 1;
	while (line <= max_line)
	{
		while (map[line][column] != '\0' && map[line][column] != '\n')
		{
			if (map[line][column] == 'P')
			{
				if (map[line][column - 1] == '3'
					|| map[line + 1][column] == '3'
					|| map[line][column + 1] == '3'
					|| map[line - 1][column] == '3')
					return (0);
			}
			column++;
		}
		column = 0;
		line++;
	}
	return (1);
}

char	**check_content(t_vars *s_vars, char **map, int line)
{
	if (check_valid_player(s_vars, map))
	{
		free_map(map, line);
		msg_error("Don't have valid path");
	}
	else
	{
		free_map(map, line);
		create_temp_map(s_vars);
		map = s_vars->map_temp;
		return (map);
	}
	return (NULL);
}

int	check_validations(t_vars *s_vars)
{
	if (valid_map_size(s_vars))
	{
		msg_error_map(s_vars, "Map size need (lines > 2)"
			"(columns > 2) && !(lines==columns)");
	}
	if (valid_map_wall(s_vars))
		msg_error_map(s_vars, "Fix wall in your map");
	if (count_players_exists(s_vars))
		msg_error_map(s_vars, "Only one Player and one Exit");
	if (valid_content(s_vars))
		msg_error_map(s_vars, "Can't put another letter difference P,E,C,1,0");
	if (check_blocks(s_vars, 'C'))
		msg_error_map(s_vars, "Collection blocked for Walls");
	if (check_blocks(s_vars, 'P'))
		msg_error_map(s_vars, "Player blocked for Walls");
	if (check_blocks(s_vars, 'E'))
		msg_error_map(s_vars, "Exit blocked for Walls");
	if (check_size(s_vars))
		msg_error_map(s_vars, "Different sizes");
	find_valid_path(s_vars, 'C');
	find_valid_path(s_vars, 'E');
	return (0);
}
