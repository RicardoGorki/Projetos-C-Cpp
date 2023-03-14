#include "../philosofers.h"

void	full_stomach(t_philo *philo)
{
	pthread_mutex_lock(philo->m_die);
	if (philo->param->eats_to_done != 0)
	{
		philo->limit_eat++;
		if (philo->limit_eat == philo->param->eats_to_done)
			philo->is_full = 1;
		pthread_mutex_unlock(philo->m_die);
	}
	else
		pthread_mutex_unlock(philo->m_die);
}

void	die(t_philo *philo)
{
	pthread_mutex_lock(philo->m_die);
	philo->param->is_dead = 1;
	pthread_mutex_unlock(philo->m_die);
	pthread_mutex_lock(philo->m_msg);
	printf("%ld %d died\n", time_now(), philo->id);
	pthread_mutex_unlock(philo->m_msg);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->my_fork->m_fork);
	pthread_mutex_lock(&philo->next_fork->m_fork);
	send_msg(philo, "has taken a fork");
	send_msg(philo, "has taken a fork");
	send_msg(philo, "is eating");
	full_stomach(philo);
	pthread_mutex_lock(philo->m_die);
	philo->last_time_eat = time_now();
	pthread_mutex_unlock(philo->m_die);
	usleep(philo->param->s_eat);
	pthread_mutex_unlock(&philo->next_fork->m_fork);
	pthread_mutex_unlock(&philo->my_fork->m_fork);
}

void	sleeping(t_philo *philo)
{
	send_msg(philo, "is sleeping");
	usleep(philo->param->s_sleep);
}

void	think(t_philo *philo)
{
	send_msg(philo, "is thinking");
}
