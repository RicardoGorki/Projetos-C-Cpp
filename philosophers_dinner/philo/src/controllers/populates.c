#include "../philosofers.h"

void	populate_philo(t_param *params, t_philo **philo)
{
	int	i;

	i = params->philo_count;
	while (i >= 1)
		push_philo(philo, i--);
}

void	populate_fork(t_param *params, t_fork **fork)
{
	int	i;

	i = params->philo_count;
	while (i >= 1)
		push_fork(fork, i--);
}

void	link_philo_params(t_philo **philo, t_param *params)
{
	t_philo	*philos;

	philos = *philo;
	params->is_dead = 0;
	while (philos)
	{
		philos->param = params;
		philos->param->philo_count = params->philo_count;
		philos->param->eats_to_done = params->eats_to_done;
		philos->param->s_die = params->s_die;
		philos->param->s_eat = params->s_eat;
		philos->param->s_sleep = params->s_sleep;
		philos->m_msg = &params->m_msg;
		philos->m_die = &params->m_die;
		philos->is_dead = &params->is_dead;
		philos = philos->next;
	}
}

void	link_philo_and_fork(t_philo **philo, t_fork **fork)
{
	t_fork	*head_fork;
	t_philo	*philos;
	t_fork	*forks;

	philos = *philo;
	forks = *fork;
	head_fork = (*fork);
	while ((philos))
	{
		if ((philos)->next == NULL)
		{
			(philos)->my_fork = (forks);
			(philos)->next_fork = head_fork;
			return ;
		}
		(philos)->my_fork = (forks);
		(philos)->next_fork = ((forks)->next);
		(philos) = (philos)->next;
		(forks) = (forks)->next;
	}
}
