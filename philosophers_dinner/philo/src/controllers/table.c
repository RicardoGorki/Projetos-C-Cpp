#include "../philosofers.h"

void	info_table(int argc, char **argv, t_param *params)
{
	params->philo_count = atoi_philo(argv[1]);
	params->time_to_die = atoi_philo(argv[2]);
	params->s_die = (params->time_to_die * 1000);
	params->time_to_eat = atoi_philo(argv[3]);
	params->s_eat = (params->time_to_eat * 1000);
	params->time_to_sleep = atoi_philo(argv[4]);
	params->s_sleep = (params->time_to_sleep * 1000);
	if (argc == 6)
		params->eats_to_done = atoi_philo(argv[5]);
	else
		params->eats_to_done = 0;
}

int	check_is_died(t_philo *philo)
{
	pthread_mutex_lock(philo->m_die);
	if (*philo->is_dead == 1)
	{
		pthread_mutex_unlock(philo->m_die);
		return (0);
	}
	else
	{
		pthread_mutex_unlock(philo->m_die);
		return (1);
	}
}

void	*die_watcher(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (check_is_died(philo) && philo->is_full != 1)
	{
		while (philo && check_is_died(philo))
		{
			pthread_mutex_lock(philo->m_die);
			if ((time_now() - philo->last_time_eat) > philo->param->time_to_die)
			{
				pthread_mutex_unlock(philo->m_die);
				die(philo);
				return (NULL);
			}
			else
				pthread_mutex_unlock(philo->m_die);
			philo = philo->next;
			usleep(100);
		}
		usleep(100);
		philo = (t_philo *)arg;
	}
	return (NULL);
}

void	mini_table(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->my_fork->m_fork);
	printf("%ld %d has taken a fork\n", time_now(), philo->id);
	pthread_mutex_unlock(&philo->next_fork->m_fork);
	usleep(philo->param->s_die);
	pthread_mutex_lock(philo->m_msg);
	printf("%ld %d died\n", time_now(), philo->id);
	pthread_mutex_unlock(philo->m_msg);
}

void	*table(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(100);
	if (philo->param->philo_count == 1)
	{
		mini_table(philo);
	}
	else
	{
		while (check_is_died(philo) && philo->is_full != 1)
		{
			if (check_is_died(philo))
				eat(philo);
			if (check_is_died(philo))
				sleeping(philo);
			if (check_is_died(philo))
				think(philo);
		}
	}
	return (NULL);
}
