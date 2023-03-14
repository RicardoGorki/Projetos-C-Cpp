#include "../philosofers.h"

t_philo	*new_philo(int id)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->id = id;
	new->next = NULL;
	return (new);
}

void	push_philo(t_philo **philos, int id)
{
	t_philo	*stack_node;

	stack_node = new_philo(id);
	stack_node->next = *philos;
	*philos = stack_node;
}

t_fork	*new_fork(int id)
{
	t_fork	*new;

	new = malloc(sizeof(t_fork));
	if (!new)
		return (NULL);
	new->id = id;
	new->next = NULL;
	return (new);
}

void	push_fork(t_fork **stack, int id)
{
	t_fork	*stack_node;

	stack_node = new_fork(id);
	stack_node->next = *stack;
	*stack = stack_node;
}
