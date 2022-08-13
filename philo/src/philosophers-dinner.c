#include "philo.h"

void	wait_philosophers(t_philosopher **philosophers, t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->number_of_philosophers)
		pthread_join(*((*philosophers)[i].thread), NULL);
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
	start_threads(&philosophers, &args);
	wait_philosophers(&philosophers, &args);
	destroy_philosophers(&philosophers, &args);
	get_time();
	return (0);
}
