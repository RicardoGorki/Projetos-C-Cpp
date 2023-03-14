#ifndef PHILOSOFERS_H
# define PHILOSOFERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_param
{
	pthread_t		p_thread;
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eats_to_done;
	int				is_dead;
	long			s_die;
	long			s_eat;
	long			s_sleep;
	pthread_mutex_t	m_msg;
	pthread_mutex_t	m_die;
}				t_param;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	m_fork;
	struct s_fork	*next;
}				t_fork;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*m_msg;
	pthread_mutex_t	*m_die;
	int				*is_dead;
	int				is_full;
	int				limit_eat;
	long			last_time_eat;
	struct s_param	*param;
	struct s_philo	*next;
	struct s_fork	*my_fork;
	struct s_fork	*next_fork;
}				t_philo;

unsigned long	atoi_philo(const char *str);
long			time_now(void);
int				my_strlen(char *s);
int				check_is_died(t_philo *philo);
void			*die_watcher(void *arg);
void			error_msg(char *msg);
void			send_msg(t_philo *philo, char *msg);
void			info_table(int argc, char **argv, t_param *params);
void			create_philo_threads(t_philo **philos);
void			push_philo(t_philo **philos, int id);
void			push_fork(t_fork **stack, int id);
void			link_philo_and_fork(t_philo **philo, t_fork **fork);
void			link_philo_params(t_philo **philo, t_param *params);
void			populate_fork(t_param *params, t_fork **fork);
void			populate_philo(t_param *params, t_philo **philo);
void			create_philos_and_forks(t_param *params,
					t_philo **philo, t_fork **fork);
void			*table(void *arg);
void			mini_table(void *arg);
void			think(t_philo *philo);
void			eat(t_philo *philo);
void			pop_philo(t_philo **philo);
void			pop_fork(t_fork **fork);
void			full_stomach(t_philo *philo);
void			vanish(t_philo **philo, t_fork **fork);
void			sleeping(t_philo *philo);
int				mutex_destroyer(t_philo **philo);
void			die(t_philo *philo);

#endif
