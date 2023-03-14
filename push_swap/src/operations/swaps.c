#include "../push_swap.h"

static int	check_size_swap(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	if (i > 1)
		return (0);
	return (1);
}

void	sa(t_stack **stack, char *msg)
{
	t_stack	*temp_x;
	t_stack	*temp_y;
	int		len;

	len = my_strlen(msg);
	if (!*stack || check_size_swap(*stack))
		return ;
	temp_x = (*stack);
	temp_y = (*stack)->next;
	(*stack) = temp_y;
	temp_x->next = temp_y->next;
	temp_y->next = temp_x;
	write(1, msg, len);
}

void	sb(t_stack **stack, char *msg)
{
	t_stack	*temp_x;
	t_stack	*temp_y;
	int		len;

	len = my_strlen(msg);
	if (!*stack || check_size_swap(*stack))
		return ;
	temp_x = (*stack);
	temp_y = (*stack)->next;
	(*stack) = temp_y;
	temp_x->next = temp_y->next;
	temp_y->next = temp_x;
	write(1, msg, len);
}

void	ss(t_stack **stack_a, t_stack **stack_b, char *msg)
{
	int	len;

	len = my_strlen(msg);
	sa(stack_a, "");
	sb(stack_b, "");
	write(1, msg, len);
}
