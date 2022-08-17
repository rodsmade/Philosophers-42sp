/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_eating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:00:40 by roaraujo          #+#    #+#             */
/*   Updated: 2022/08/17 18:00:48 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	i_should_die_before_i_wake(t_philo_data *philosopher, time_t action_ms)
{
	time_t	time_alive_us;
	time_t	time_left_to_live_us;
	time_t	current_time_usec;

	get_curr_time_abs_usec(&current_time_usec);
	time_alive_us = current_time_usec - philosopher->last_meal_abs_usec;
	time_left_to_live_us = philosopher->time_to_die_ms * 1000 - time_alive_us;
	if (time_left_to_live_us < 0)
	{
		write_halt(philosopher->halt, &philosopher->common->halt_mutex, true);
		return (true);
	}
	if (time_left_to_live_us - action_ms * 1000 < 0)
	{
		usleep(time_left_to_live_us);
		write_halt(philosopher->halt, &philosopher->common->halt_mutex, true);
		wprintf(philosopher, DIE);
		return (true);
	}
	return (false);
}

void	unlock_locks(pthread_mutex_t *left_fork, pthread_mutex_t *right_fork)
{
	if (left_fork)
		pthread_mutex_unlock(left_fork);
	if (right_fork)
		pthread_mutex_unlock(right_fork);
	return ;
}

void	decide_sleep_time(t_philo_data *philosopher)
{
	if (philosopher->time_to_eat_ms > philosopher->time_to_die_ms)
	{
		usleep(philosopher->time_to_die_ms * 1000);
		write_halt(philosopher->halt, &philosopher->common->halt_mutex, true);
		wprintf(philosopher, DIE);
	}
	else
	{
		get_curr_time_abs_usec(&philosopher->last_meal_abs_usec);
		wprintf(philosopher, EAT);
		usleep(philosopher->time_to_eat_ms * 1000);
		philosopher->meals_had++;
	}
	return ;
}
