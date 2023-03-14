#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				index;
	int				content;
	struct s_stack	*next;
}	t_stack;

int			list_len(t_stack *stack);
int			check_sorted_list(t_stack **stack, int max);
int			check_duplicates(int *stack, int argc);
int			len_bit(int max);
int			my_strlen(char *s);
long int	atoi_ps(const char *str, int *stack);
char		*exceptions_handling(int *stack, int argc);
void		free_main(t_stack **stack_a, t_stack **stack_b, int *stack);
void		pop(t_stack **stack);
void		put_index(t_stack **stack_a);
void		push(t_stack **stack, int content, int index);
void		error_msg(int *stack, char *msg);
void		sort_two(t_stack **stack_a, int max);
void		sort_three(t_stack **stack_a, int max);
void		sort_four(t_stack **stack_a, t_stack **stack_b, int max);
void		sort_five(t_stack **stack_a, t_stack **stack_b, int max);
void		sort_rest(t_stack **stack_a, t_stack **stack_b, int max);
void		bubble_sort(t_stack **stack);
void		sort_stack(t_stack **stack_a, t_stack **stack_b, int *stack);
void		sa(t_stack **stack, char *msg);
void		sb(t_stack **stack, char *msg);
void		ss(t_stack **stack_a, t_stack **stack_b, char *msg);
void		pa(t_stack **stack_a, t_stack **stack_b, char *msg);
void		pb(t_stack **stack_a, t_stack **stack_b, char *msg);
void		ra(t_stack **stack, char *msg);
void		rb(t_stack **stack, char *msg);
void		rr(t_stack **stack_a, t_stack **stack_b, char *msg);
void		rra(t_stack **stack, char *msg);
void		rrb(t_stack **stack, char *msg);
void		rrr(t_stack **stack_a, t_stack **stack_b, char *msg);

#endif
