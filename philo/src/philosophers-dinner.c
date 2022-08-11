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

void init_philosophers(t_philosopher **philosophers, t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->number_of_philosophers)
		(*philosophers)[i].args = args;
	return ;
}

int main(int argc, char *argv[])
{
	t_args			args;
	t_philosopher	*philosophers;

	printf("hello world\n");
	if (argc < 5 || argc > 6)
		return (-1);
	get_args(argv, &args);
	philosophers = malloc(args.number_of_philosophers * sizeof(t_philosopher));
	init_philosophers(&philosophers, &args);
	printf("number_of_philosophers: %i\n", philosophers[0].args->number_of_philosophers);
	printf("time_to_die: %i\n", philosophers[0].args->time_to_die);
	printf("time_to_eat: %i\n", philosophers[0].args->time_to_eat);
	printf("time_to_sleep: %i\n", philosophers[0].args->time_to_sleep);
	printf("number of meals: %i\n", philosophers[0].args->number_of_meals);
	printf("number_of_philosophers: %i\n", philosophers[1].args->number_of_philosophers);
	printf("time_to_die: %i\n", philosophers[1].args->time_to_die);
	printf("time_to_eat: %i\n", philosophers[1].args->time_to_eat);
	printf("time_to_sleep: %i\n", philosophers[1].args->time_to_sleep);
	printf("number of meals: %i\n", philosophers[1].args->number_of_meals);
	printf("number_of_philosophers: %i\n", philosophers[2].args->number_of_philosophers);
	printf("time_to_die: %i\n", philosophers[2].args->time_to_die);
	printf("time_to_eat: %i\n", philosophers[2].args->time_to_eat);
	printf("time_to_sleep: %i\n", philosophers[2].args->time_to_sleep);
	printf("number of meals: %i\n", philosophers[2].args->number_of_meals);
	args.number_of_meals = 10;
	printf("number of meals: %i\n", philosophers[0].args->number_of_meals);
	printf("number of meals: %i\n", philosophers[1].args->number_of_meals);
	printf("number of meals: %i\n", philosophers[2].args->number_of_meals);
	// printf("number of meals: %i\n", number_of_meals);
	return (0);
}