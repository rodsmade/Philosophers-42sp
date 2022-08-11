#include "philo.h"

void	init_philosophers(t_philosopher **philosophers, t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->number_of_philosophers)
	{
		(*philosophers)[i].args = args;
		(*philosophers)[i].index = i + 1;
		printf("firosofo %d\n", (*philosophers)[i].index);
		(*philosophers)[i].thread = (pthread_t *)malloc(sizeof(pthread_t));
		(*philosophers)[i].this_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	}
	i = -1;
	while (++i < args->number_of_philosophers)
		pthread_mutex_init((*philosophers)[i].this_fork, NULL);
	i = -1;
	// while (++i < args->number_of_philosophers)
	// {
	// 	(*philosophers)[i].next_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	// 	if (i == (args->number_of_philosophers - 1))
	// 		(*philosophers)[i].next_fork = &((*philosophers)[0].this_fork);
	// 	else
	// 		(*philosophers)[i].next_fork = &((*philosophers)[i + 1].this_fork);
	// }
}
