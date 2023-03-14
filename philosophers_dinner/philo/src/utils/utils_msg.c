#include "../philosofers.h"

void	error_msg(char *msg)
{
	size_t	len;

	len = my_strlen(msg);
	write(1, "Error\n", 6);
	write(1, msg, len);
	exit(0);
}

long	time_now(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	send_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(philo->m_msg);
	if (check_is_died(philo))
	{
		printf("%ld %d %s\n", time_now(), philo->id, msg);
		pthread_mutex_unlock(philo->m_msg);
	}
	else
		pthread_mutex_unlock(philo->m_msg);
}
