#include "philo.h"

void	eat(t_philosopher *philosopher)
{
	printf("philosopher %d is eating...\n", philosopher->index);
}

void *philosopher_routine(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	printf("philosopher %d was born\n", philosopher->index);
	pthread_mutex_lock((*philosopher).this_fork);
	printf("philosopher %d take this fork\n", philosopher->index);
	pthread_mutex_lock((*philosopher).next_fork);
	printf("philosopher %d take next fork\n", philosopher->index);
	eat(philosopher);
	usleep(200);
	pthread_mutex_unlock(((*philosopher).this_fork));
	printf("philosopher %d put this fork\n", philosopher->index);
	pthread_mutex_unlock(((*philosopher).next_fork));
	printf("philosopher %d put next fork\n", philosopher->index);
	return (0);
}

void	start_threads(t_philosopher **philosophers, t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->number_of_philosophers)
	{
		pthread_create((*philosophers)[i].thread, NULL, &philosopher_routine, (void *)((*philosophers) + i));
	}
	return ;
}
