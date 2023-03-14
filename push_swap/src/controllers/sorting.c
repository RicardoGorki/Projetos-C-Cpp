#include "../push_swap.h"

void	sort_two(t_stack **stack_a, int max)
{
	while (check_sorted_list(stack_a, max))
		sa(stack_a, "sa\n");
}

void	sort_three(t_stack **stack_a, int max)
{
	while (check_sorted_list(stack_a, max))
	{
		if ((((*stack_a))->index > ((*stack_a))->next->index)
			&& (((*stack_a))->next->index < ((*stack_a))->next->next->index)
			&& (((*stack_a))->index > ((*stack_a))->next->next->index))
			ra(stack_a, "ra\n");
		else if (((*stack_a))->index > ((*stack_a))->next->index)
			sa(stack_a, "sa\n");
		else if (((*stack_a))->index < ((*stack_a))->next->index
			&& ((*stack_a))->next->index > ((*stack_a))->next->next->index)
			rra(stack_a, "rra\n");
	}
}

void	sort_four(t_stack **stack_a, t_stack **stack_b, int max)
{
	int	max_temp;

	max_temp = max;
	while (check_sorted_list(stack_a, max))
	{
		if (((*stack_a)->index == 1) && (max != 3))
		{
			pb(stack_a, stack_b, "pb\n");
			max_temp--;
		}
		if (max_temp == 3)
		{
			sort_three(stack_a, max_temp);
			pa(stack_a, stack_b, "pa\n");
			return ;
		}
		ra(stack_a, "ra\n");
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b, int max)
{
	int	len_b;

	while (check_sorted_list(stack_a, max))
	{
		if ((*stack_a)->index == 1)
			pb(stack_a, stack_b, "pb\n");
		if ((*stack_a)->index == 2)
			pb(stack_a, stack_b, "pb\n");
		len_b = list_len(*stack_b);
		if (len_b == 2 && (*stack_b)->index < (*stack_b)->next->index)
			sb(stack_b, "sb\n");
		if (len_b == 2)
		{
			sort_three(stack_a, 3);
			pa(stack_a, stack_b, "pa\n");
			pa(stack_a, stack_b, "pa\n");
			return ;
		}
		rra(stack_a, "rra\n");
	}
}

void	sort_rest(t_stack **stack_a, t_stack **stack_b, int max)
{
	int	bit_check;
	int	count;
	int	max_bit;

	max_bit = len_bit(max);
	bit_check = 0;
	while (check_sorted_list(stack_a, max))
	{
		count = max;
		while (bit_check < max_bit && count > 0)
		{
			if ((((*stack_a)->index >> bit_check) & 1) == 0)
				pb(stack_a, stack_b, "pb\n");
			else
				ra(stack_a, "ra\n");
			count--;
		}
		while (*stack_b)
			pa(stack_a, stack_b, "pa\n");
		bit_check++;
	}
}
