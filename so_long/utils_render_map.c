#include "so_long.h"

void	get_size_map(t_vars *s_vars, char *arg_map)
{
	int		fd;
	int		lines;
	char	*str;

	fd = open(arg_map, O_RDONLY);
	if (fd == -1)
		msg_error("File does not exist");
	lines = 0;
	str = get_next_line(fd);
	s_vars->height = my_strlen(str) - 1;
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		lines++;
	}
	free(str);
	close(fd);
	s_vars->width = lines;
}

int	create_map(t_vars *s_vars, char *arg_map)
{
	int	fd;
	int	lines;
	int	len;

	s_vars->arg_path = arg_map;
	fd = open(arg_map, O_RDONLY);
	if (fd == -1)
		msg_error("File does not exist");
	lines = 0;
	s_vars->map_arg = get_next_line(fd);
	len = my_strlen(s_vars->map_arg);
	s_vars->map = my_calloc(sizeof(char *), len + 1);
	if (!s_vars->map)
		return (0);
	while (s_vars->map_arg)
	{
		s_vars->map[lines] = s_vars->map_arg;
		render_map(s_vars, lines++);
		s_vars->map_arg = get_next_line(fd);
	}
	s_vars->map_size = lines;
	close(fd);
	return (0);
}

char	**create_temp_map(t_vars *s_vars)
{
	int	fd;
	int	lines;
	int	len;

	fd = open(s_vars->arg_path, O_RDONLY);
	if (fd == -1)
		msg_error("File does not exist");
	lines = 0;
	s_vars->map_arg = get_next_line(fd);
	len = my_strlen(s_vars->map_arg);
	s_vars->map_temp = my_calloc(sizeof(char *), len + 1);
	if (!s_vars->map_temp)
		return (0);
	while (s_vars->map_arg)
	{
		s_vars->map_temp[lines] = s_vars->map_arg;
		s_vars->map_arg = get_next_line(fd);
		lines++;
	}
	close(fd);
	return (s_vars->map_temp);
}

int	render_map(t_vars *s_vars, int lines)
{
	int		i;
	int		column;

	i = 0;
	column = 0;
	while (s_vars->map_arg[i] != '\0')
	{
		if (s_vars->map_arg[i] == '0')
			put_image(s_vars, FLOOR, lines, column++);
		if (s_vars->map_arg[i] == '1')
			put_image(s_vars, WALL, lines, column++);
		if (s_vars->map_arg[i] == 'C')
		{
			s_vars->get_collection += 1;
			put_image(s_vars, CAT, lines, column++);
		}
		if (s_vars->map_arg[i] == 'E')
			put_image(s_vars, LEAVE, lines, column++);
		if (s_vars->map_arg[i] == 'P')
			put_image(s_vars, CHARACTER, lines, column++);
		i++;
	}
	return (0);
}
