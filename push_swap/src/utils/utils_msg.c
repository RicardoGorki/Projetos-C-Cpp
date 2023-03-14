#include "../push_swap.h"

void	error_msg(int *stack, char *msg)
{
	int	len;

	len = my_strlen(msg);
	write(1, "Error\n", 6);
	write(1, msg, len);
	free(stack);
	exit(0);
}
