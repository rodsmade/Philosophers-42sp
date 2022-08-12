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
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_meals;
}		t_args;

typedef struct s_philosopher
{
	int			index;
	t_args		*args;
	pthread_t	*thread;
	pthread_mutex_t	*this_fork;
	pthread_mutex_t	*next_fork;
}		t_philosopher;

// ----------------------------------------------	PROTOTYPES	----------------
// destroy_routine.c
void	destroy_philosophers(t_philosopher **philosophers, t_args *args);

// init_routine.c
void	init_philosophers(t_philosopher **philosophers, t_args *args);

// get_args.c
void	get_args(char *argv[], t_args *args);

// get_time.c
int get_time(void);

// utils.c
int		ft_atoi(const	char *str);



#endif
