/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_data_race.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:35:48 by roaraujo          #+#    #+#             */
/*   Updated: 2022/08/21 14:39:05 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	read_var(int *var, pthread_mutex_t *mutex)
{
	int	temp;

	pthread_mutex_lock(mutex);
	temp = *var;
	pthread_mutex_unlock(mutex);
	return (temp);
}

void	write_var(int *var, pthread_mutex_t *mutex, int status)
{
	pthread_mutex_lock(mutex);
	*var = status;
	pthread_mutex_unlock(mutex);
}

time_t	read_last_meal_abs_us(t_philo_data *philo)
{
	time_t	temp;

	pthread_mutex_lock(philo->last_meal_mutex);
	temp = philo->last_meal_abs_usec;
	pthread_mutex_unlock(philo->last_meal_mutex);
	return (temp);
}

void	write_last_meal_abs_us(t_philo_data *philo)
{
	time_t	current_time_abs_usec;

	get_curr_time_abs_usec(&current_time_abs_usec);
	pthread_mutex_lock(philo->last_meal_mutex);
	philo->last_meal_abs_usec = current_time_abs_usec;
	pthread_mutex_unlock(philo->last_meal_mutex);
	return ;
}
