#include "philo.h"

void	get_args(char *argv[], t_args *args)
{
	(*args).number_of_philosophers = ft_atoi(argv[1]);
	(*args).time_to_die = ft_atoi(argv[2]);
	(*args).time_to_eat = ft_atoi(argv[3]);
	(*args).time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		(*args).number_of_meals = ft_atoi(argv[5]);
	else
		(*args).number_of_meals = -42;
	return ;
}
