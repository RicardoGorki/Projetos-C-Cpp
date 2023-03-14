#include "philosofers.h"

int	main(int argc, char **argv)
{
	t_param		params;
	t_philo		**philo;
	t_fork		**fork;

	if (argc > 4 && argc <= 6)
	{
		info_table(argc, argv, &params);
		philo = malloc(sizeof(t_philo));
		fork = malloc(sizeof(t_fork));
		if (!philo || !fork)
			return (0);
		create_philos_and_forks(&params, philo, fork);
		create_philo_threads(philo);
		vanish(philo, fork);
	}
	return (0);
}
