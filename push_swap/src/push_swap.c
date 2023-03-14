#include "push_swap.h"

void	free_main(t_stack **stack_a, t_stack **stack_b, int *stack)
{
	free(stack);
	free(stack_a);
	free(stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	int		*stack;
	int		i;
	int		j;

	if (argc > 1)
	{
		j = 0;
		i = 1;
		stack = malloc(sizeof(int) * (argc - 1));
		if (!stack)
			return (0);
		while (argv[i] && i < argc)
			stack[j++] = atoi_ps(argv[i++], stack);
		exceptions_handling(stack, (argc - 1));
		stack_a = malloc(sizeof(t_stack));
		stack_b = malloc(sizeof(t_stack));
		if (!stack_a || !stack_b)
			return (0);
		while (j)
			push(stack_a, stack[--j], 0);
		sort_stack(stack_a, stack_b, stack);
	}
	return (0);
}
