#include "../push_swap.h"

void	ra(t_stack **stack, char *msg)
{
	t_stack	*temp_top;
	t_stack	*temp_head;
	t_stack	*temp_base;
	int		len;

	len = my_strlen(msg);
	temp_top = *stack;
	temp_head = (*stack)->next;
	while (*stack != NULL)
	{
		if ((*stack)->next == NULL)
		{
			temp_base = *stack;
			*stack = temp_head;
			temp_base->next = temp_top;
			temp_top->next = NULL;
			write(1, msg, len);
			return ;
		}
		*stack = (*stack)->next;
	}
}

void	rb(t_stack **stack, char *msg)
{
	t_stack	*temp_top;
	t_stack	*temp_head;
	t_stack	*temp_base;
	int		len;

	len = my_strlen(msg);
	temp_top = *stack;
	temp_head = (*stack)->next;
	while (*stack != NULL)
	{
		if ((*stack)->next == NULL)
		{
			temp_base = *stack;
			*stack = temp_head;
			temp_base->next = temp_top;
			temp_top->next = NULL;
			write(1, msg, len);
			return ;
		}
		*stack = (*stack)->next;
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b, char *msg)
{
	int	len;

	len = my_strlen(msg);
	ra(stack_a, "");
	rb(stack_b, "");
	write(1, msg, len);
}
