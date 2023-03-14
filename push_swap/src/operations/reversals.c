#include "../push_swap.h"

void	rra(t_stack **stack, char *msg)
{
	t_stack	*temp_top;
	t_stack	*temp_base;
	t_stack	*temp_last;
	int		len;

	len = my_strlen(msg);
	temp_top = *stack;
	while (*stack != NULL)
	{
		if ((*stack)->next != NULL)
			if ((*stack)->next->next == NULL)
				temp_last = (*stack);
		if ((*stack)->next == NULL)
		{
			temp_base = *stack;
			temp_base->next = temp_top;
			temp_last->next = NULL;
			write(1, msg, len);
			return ;
		}
		*stack = (*stack)->next;
	}
}

void	rrb(t_stack **stack, char *msg)
{
	t_stack	*temp_top;
	t_stack	*temp_base;
	t_stack	*temp_last;
	int		len;

	len = my_strlen(msg);
	temp_top = *stack;
	while (*stack != NULL)
	{
		if ((*stack)->next != NULL)
			if ((*stack)->next->next == NULL)
				temp_last = (*stack);
		if ((*stack)->next == NULL)
		{
			temp_base = *stack;
			temp_base->next = temp_top;
			temp_last->next = NULL;
			write(1, msg, len);
			return ;
		}
		*stack = (*stack)->next;
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b, char *msg)
{
	int	len;

	len = my_strlen(msg);
	rra(stack_a, "");
	rrb(stack_b, "");
	write(1, msg, len);
}
