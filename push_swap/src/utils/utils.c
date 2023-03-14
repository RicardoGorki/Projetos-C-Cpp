#include "../push_swap.h"

int	list_len(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	check_sorted_list(t_stack **stack, int max)
{
	t_stack	*tmp;
	int		len;

	len = list_len(*stack);
	tmp = *stack;
	if (len != max)
		return (1);
	while (tmp)
	{
		if (tmp->next != NULL)
			if (tmp->index > tmp->next->index)
				return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	len_bit(int max)
{
	int	i;

	i = 0;
	while ((max >> i) != 0)
		i++;
	return (i);
}
