#include "so_long.h"

int	check_size(t_vars *s_vars)
{
	int	line;
	int	size;
	int	max_line;

	max_line = s_vars->map_size - 1;
	line = 0;
	size = (int)my_strlen(s_vars->map[line]);
	while (max_line)
	{
		if (size != (int)my_strlen(s_vars->map[max_line]))
			return (1);
		max_line--;
	}
	return (0);
}
