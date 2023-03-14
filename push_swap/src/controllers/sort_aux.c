#include "../push_swap.h"

static void	swap_content(t_stack **stack)
{
	int	temp;

	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
}

void	bubble_sort(t_stack **stack)
{
	t_stack	*aux;
	int		swapped;

	swapped = 1;
	while (swapped)
	{
		aux = *stack;
		swapped = 0;
		while ((aux)->next)
		{
			if ((aux)->content > (aux)->next->content)
			{
				swap_content(&aux);
				swapped = 1;
			}
			aux = (aux)->next;
		}
		if (swapped == 0)
			break ;
	}
}

static void	transfer_index(t_stack *tmp, t_stack **head_temp,
	t_stack **aux, t_stack **stack)
{
	int	len;

	while ((tmp) != NULL)
	{
		aux = stack;
		while (*aux)
		{
			if ((*aux)->content == (tmp)->content && (*aux)->index == 0)
			{
				(*aux)->index = (tmp)->index;
				tmp = *head_temp;
			}
			(aux) = &(*aux)->next;
		}
		tmp = (tmp)->next;
	}
	len = list_len(*head_temp);
	while (len)
	{
		pop(head_temp);
		len--;
	}
}

static void	set_index(t_stack *tmp)
{
	int	i;

	i = 1;
	while (tmp)
	{
		(tmp)->index = i++;
		tmp = (tmp)->next;
	}
}

void	put_index(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	**aux;
	t_stack	**head_temp;
	t_stack	*t;

	t = NULL;
	head_temp = &t;
	aux = stack;
	while ((*aux))
	{
		push(head_temp, (*aux)->content, (*aux)->index);
		aux = &(*aux)->next;
	}
	tmp = *head_temp;
	bubble_sort(&tmp);
	set_index(tmp);
	transfer_index(tmp, head_temp, aux, stack);
}
