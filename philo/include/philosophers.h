/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:10:25 by roaraujo          #+#    #+#             */
/*   Updated: 2022/08/21 09:07:17 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// ---------------------------------------------	DEFINES		----------------
# define DIE "died"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"

// ---------------------------------------------	INCLUDES	----------------
# include <pthread.h> // threads and mutexes functions
# include <stdio.h> // printf()
# include <unistd.h> // usleep()
# include <stdlib.h> // malloc(), free()
# include <sys/time.h> // gettimeofday()
# include <stdbool.h> // bool typedef
# include <limits.h> // INT_MAX definition
# include "ansi_color_codes.h" // cool stuff

// ----------------------------------------------	STRUCTS		----------------

typedef struct s_common_data
{
	int				nb_of_philos;
	int				time_to_eat_ms;
	int				time_to_sleep_ms;
	int				time_to_die_ms;
	int				nb_of_meals;
	bool			infinite_dinner;
	bool			halt_execution;
	bool			first_death;
	time_t			pgm_started_abs_usec;
	pthread_mutex_t	printf_mutex;
	pthread_mutex_t	halt_mutex;
}		t_common_data;

typedef struct s_philo_data
{
	int					id;
	int					meals_had;
	int					time_to_eat_ms;
	int					time_to_sleep_ms;
	int					time_to_die_ms;
	int					nb_of_meals;
	bool				infinite_dinner;
	bool				*halt;
	time_t				last_meal_abs_usec;
	pthread_t			*thread;
	pthread_mutex_t		*this_fork;
	pthread_mutex_t		*lefthand_fork;
	pthread_mutex_t		*righthand_fork;
	t_common_data		*common;
}		t_philo_data;

// ----------------------------------------------	PROTOTYPES	----------------
// args_check.c
bool		passes_arg_check(int argc, char *argv[], t_common_data *common);

// data_destroy.c
void		unlock_the_locks(pthread_mutex_t *left_fork,
				pthread_mutex_t *right_fork);
void		ft_free_ptr(void **ptr);
void		free_up_memory(t_philo_data **philosophers);

// data_init.c
void		initialise_data(t_philo_data **philos, t_common_data *common);

// utils_data_race.c
bool		read_var(bool *var, pthread_mutex_t *mutex);
void		write_var(bool *var, pthread_mutex_t *mutex, bool status);

// solo_dining.c
int			one_philo(t_philo_data *one_philo);

// utils_number_handling.c
bool		ft_isnumeric_s(char *str);
long int	ft_atoli(const char *nptr);

// utils_printing.c
void		wprintf(t_philo_data *philo, char *action);
bool		must_halt(t_philo_data *philo);

// utils_timestamp.c
void		get_curr_time_abs_usec(time_t *current_time);
int			time_elapsed_ms(unsigned long int baseline_abs_usec);

#endif