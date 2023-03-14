#include "../push_swap.h"

int	check_duplicates(int *stack, int argc)
{
	int	i;
	int	j;
	int	len;

	len = argc;
	i = 0;
	while (i < len)
	{
		j = i;
		if (stack[i] == stack[j + 1] && j + 1 < len)
			return (1);
		while (j + 1 < len)
		{
			if (stack[i] == stack[j + 1] && j + 1 < len)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
