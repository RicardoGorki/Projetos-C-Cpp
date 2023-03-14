#include "so_long.h"

int	check_extension(char *map_name)
{
	char	*temp_str;
	char	*extension;
	int		result;

	extension = ".ber";
	temp_str = my_strrchr(map_name, '.');
	if (temp_str == NULL)
		msg_error("Extension need .ber");
	result = my_strncmp(temp_str, extension, 5);
	if (result != 0)
		return (1);
	return (0);
}

int	valid_map_size(t_vars *s_vars)
{
	int	lines;
	int	columns;

	lines = s_vars->map_size;
	columns = my_strlen(s_vars->map[0]) - 1;
	if ((lines < 3) || (columns < 3) || (lines == columns))
		return (1);
	return (0);
}

int	valid_map_wall(t_vars *s_vars)
{
	int	lines;
	int	line;
	int	column;
	int	col_len;

	lines = s_vars->map_size;
	line = 0;
	column = 1;
	col_len = my_strlen(s_vars->map[line]) - 2;
	while (line != lines)
	{
		if (s_vars->map[line][0] != '1' || s_vars->map[line][col_len] != '1')
			return (1);
		line++;
	}
	lines -= 1;
	while (column < col_len)
	{
		if (s_vars->map[0][column] != '1' || s_vars->map[lines][column] != '1')
			return (1);
		column++;
	}
	return (0);
}

int	count_players_exists(t_vars *s_vars)
{
	int	lines;
	int	line;
	int	column;

	lines = s_vars->map_size;
	line = 0;
	while (lines)
	{
		column = 0;
		while (s_vars->map[line][column] != '\0'
			&& s_vars->map[line][column] != '\n')
		{
			if (s_vars->map[line][column] == 'P')
				s_vars->p_count++;
			if (s_vars->map[line][column] == 'E')
				s_vars->e_count++;
			column++;
		}
		line++;
		lines--;
	}
	if (s_vars->p_count != 1 || s_vars->e_count != 1)
		return (1);
	return (0);
}

int	valid_content(t_vars *s_vars)
{
	int	lines;
	int	line;
	int	column;

	lines = s_vars->map_size;
	line = 0;
	while (lines)
	{
		column = 0;
		while (s_vars->map[line][column] != '\n')
		{
			if (s_vars->map[line][column] != 'P'
					&& s_vars->map[line][column] != 'E'
					&& s_vars->map[line][column] != '0'
					&& s_vars->map[line][column] != 'C'
					&& s_vars->map[line][column] != '1')
				return (1);
			column++;
		}
		line++;
		lines--;
	}
	if (s_vars->get_collection <= 0)
		msg_error("Need one or more collectable");
	return (0);
}
