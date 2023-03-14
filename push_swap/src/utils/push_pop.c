#include "../push_swap.h"

t_stack	*new_stack(int content, int index)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = index;
	new->next = NULL;
	return (new);
}

void	push(t_stack **stack, int content, int index)
{
	t_stack	*stack_node;

	stack_node = new_stack(content, index);
	stack_node->next = *stack;
	*stack = stack_node;
}

void	pop(t_stack **stack)
{
	t_stack	*temp;

	temp = NULL;
	if (!*stack)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
