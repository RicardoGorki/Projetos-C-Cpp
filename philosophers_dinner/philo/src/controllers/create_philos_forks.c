#include "../philosofers.h"

void	create_philos_and_forks(t_param *params, t_philo **philo, t_fork **fork)
{
	populate_philo(params, philo);
	populate_fork(params, fork);
	link_philo_and_fork(philo, fork);
	link_philo_params(philo, params);
}
