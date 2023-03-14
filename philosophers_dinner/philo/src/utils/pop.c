#include "../philosofers.h"

void	pop_philo(t_philo **philo)
{
	t_philo	*temp;

	temp = NULL;
	if (!*philo)
		return ;
	temp = *philo;
	*philo = (*philo)->next;
	free(temp);
}

void	pop_fork(t_fork **fork)
{
	t_fork	*temp;

	temp = NULL;
	if (!*fork)
		return ;
	temp = *fork;
	*fork = (*fork)->next;
	free(temp);
}
