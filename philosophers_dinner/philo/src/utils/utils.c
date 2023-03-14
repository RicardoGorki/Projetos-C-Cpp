#include "../philosofers.h"

void	vanish(t_philo **philo, t_fork **fork)
{
	while (*fork)
		pop_fork(fork);
	while (*philo)
		pop_philo(philo);
	free(philo);
	free(fork);
}
