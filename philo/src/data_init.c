/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:10:40 by roaraujo          #+#    #+#             */
/*   Updated: 2022/08/21 09:28:42 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_common_data(t_common_data *common)
{
	common->halt_execution = false;
	common->first_death = true;
	get_curr_time_abs_usec(&(common->pgm_started_abs_usec));
	pthread_mutex_init(&common->printf_mutex, NULL);
	pthread_mutex_init(&common->halt_mutex, NULL);
	return ;
}

void	assign_forks(t_philo_data **philos, int philos_number)
{
	int	i;

	i = -1;
	while (++i < philos_number - 1)
	{
		(*philos)[i].lefthand_fork = (*philos)[i].this_fork;
		(*philos)[i].righthand_fork = (*philos)[i + 1].this_fork;
	}
	(*philos)[i].lefthand_fork = (*philos)[0].this_fork;
	(*philos)[i].righthand_fork = (*philos)[i].this_fork;
	return ;
}

void	init_philos_array(t_philo_data **philos, t_common_data *common)
{
	int	i;

	*philos = malloc(common->nb_of_philos * sizeof(t_philo_data));
	i = -1;
	while (++i < common->nb_of_philos)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].meals_had = 0;
		(*philos)[i].time_to_eat_ms = common->time_to_eat_ms;
		(*philos)[i].time_to_sleep_ms = common->time_to_sleep_ms;
		(*philos)[i].time_to_die_ms = common->time_to_die_ms;
		(*philos)[i].nb_of_meals = common->nb_of_meals;
		(*philos)[i].infinite_dinner = common->infinite_dinner;
		(*philos)[i].halt = &common->halt_execution;
		(*philos)[i].last_meal_abs_usec = common->pgm_started_abs_usec;
		(*philos)[i].this_fork = malloc(sizeof(pthread_mutex_t));
		(*philos)[i].thread = malloc(sizeof(pthread_t));
		(*philos)[i].common = common;
	}
	i = -1;
	while (++i < common->nb_of_philos)
		pthread_mutex_init((*philos)[i].this_fork, NULL);
	assign_forks(philos, common->nb_of_philos);
	return ;
}

void	initialise_data(t_philo_data **philos, t_common_data *common)
{
	init_common_data(common);
	// printf("time to die: %i\n",common->time_to_die_ms);
	// printf("time to eat: %i\n",common->time_to_eat_ms);
	// printf("time to sleep: %i\n",common->time_to_sleep_ms);
	// printf("nb of philos: %i\n",common->nb_of_philos);
	// printf("nb of meals: %i\n",common->nb_of_meals);
	init_philos_array(philos, common);
	return ;
}
