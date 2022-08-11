#ifndef PHILO_H
# define PHILO_H

// ---------------------------------------------	INCLUDES	----------------
# include <pthread.h> // threads and mutexes functions
# include <stdio.h> // printf()
# include <unistd.h> // usleep()
# include <stdlib.h> // malloc(), free()
# include <sys/time.h> // gettimeofday()
# include <stdbool.h> // bool
# include <string.h> // memset()

// ----------------------------------------------	STRUCTS		----------------
typedef struct s_args
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_meals;
}		t_args;

typedef struct s_philosopher
{
	t_args		*args;
	pthread_t	thread;
}		t_philosopher;

// ----------------------------------------------	PROTOTYPES	----------------
int	ft_atoi(const	char *str);
int	ft_isdigit(int c);

#endif