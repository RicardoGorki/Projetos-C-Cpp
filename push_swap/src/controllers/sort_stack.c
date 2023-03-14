#include "../push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int *stack)
{
	int	max;

	max = list_len(*stack_a);
	put_index(stack_a);
	if (max == 2)
		sort_two(stack_a, max);
	if (max == 3)
		sort_three(stack_a, max);
	if (max == 4)
		sort_four(stack_a, stack_b, max);
	if (max == 5)
		sort_five(stack_a, stack_b, max);
	if (max > 5)
		sort_rest(stack_a, stack_b, max);
	while (*stack_a)
		pop(stack_a);
	free_main(stack_a, stack_b, stack);
}
