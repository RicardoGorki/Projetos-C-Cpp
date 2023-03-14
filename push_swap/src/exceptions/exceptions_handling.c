#include "../push_swap.h"

char	*exceptions_handling(int *stack, int argc)
{
	if (check_duplicates(stack, argc))
		error_msg(stack, "Do not enter duplicate numbers\n");
	return (NULL);
}
