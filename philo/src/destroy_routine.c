#include "philo.h"

void	destroy_philosophers(t_philosopher **philosophers, t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->number_of_philosophers)
	{
		free((*philosophers)[i].thread);
		pthread_mutex_destroy((*philosophers)[i].this_fork);
		free((*philosophers)[i].this_fork);
	}
	free(*philosophers);
}
