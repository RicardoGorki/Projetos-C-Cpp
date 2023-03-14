#include "../push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b, char *msg)
{
	int	len;

	len = my_strlen(msg);
	if (!*stack_b)
		return ;
	push(stack_a, (*stack_b)->content, (*stack_b)->index);
	pop(stack_b);
	write(1, msg, len);
}

void	pb(t_stack **stack_a, t_stack **stack_b, char *msg)
{
	int	len;

	len = my_strlen(msg);
	if (!*stack_a)
		return ;
	push(stack_b, (*stack_a)->content, (*stack_a)->index);
	pop(stack_a);
	write(1, msg, len);
}
