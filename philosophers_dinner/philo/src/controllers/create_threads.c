#include "../philosofers.h"

int	mutex_destroyer(t_philo **philo)
{
	t_philo	*philos;

	philos = *philo;
	if (pthread_mutex_destroy(philos->m_die) != 0)
		return (-1);
	if (pthread_mutex_destroy(philos->m_msg) != 0)
		return (-1);
	if (pthread_mutex_destroy(&(*philo)->my_fork->m_fork) != 0)
		return (-1);
	return (0);
}

void	create_philo_threads(t_philo **philos)
{
	t_philo	*philo;

	philo = *philos;
	pthread_mutex_init(philo->m_msg, NULL);
	pthread_mutex_init(philo->m_die, NULL);
	while (philo)
	{
		pthread_mutex_init(&philo->my_fork->m_fork, NULL);
		philo->last_time_eat = time_now();
		pthread_create(&(philo)->thread, NULL, table, philo);
		philo = philo->next;
	}
	philo = *philos;
	if ((*philos)->param->philo_count > 1)
		pthread_create(&(philo->param)->p_thread, NULL, die_watcher, *philos);
	while (philo)
	{
		pthread_join((philo)->thread, NULL);
		philo = philo->next;
	}
	philo = *philos;
	if ((*philos)->param->philo_count > 1)
		pthread_join((philo->param)->p_thread, NULL);
	mutex_destroyer(philos);
}
