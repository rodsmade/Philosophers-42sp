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
		(*args).number_of_meals = ft_atoi(argv[5]) == -42;
}

int main(int argc, char *argv[])
{
	t_args			args;

	printf("hello world\n");
	if (argc < 5 || argc > 6)
		return (-1);
	get_args(argv, &args);
	printf("number_of_philosophers: %i\n", args.number_of_philosophers);
	printf("time_to_die: %i\n", args.time_to_die);
	printf("time_to_eat: %i\n", args.time_to_eat);
	printf("time_to_sleep: %i\n", args.time_to_sleep);
	printf("number of meals: %i\n", args.number_of_meals);
	return (0);
}