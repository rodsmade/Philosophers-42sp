/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 10:11:26 by roaraujo          #+#    #+#             */
/*   Updated: 2022/08/21 10:12:35 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat(t_philo_data *philo)
{
	pthread_mutex_lock(philo->lefthand_fork);
	wprintf(philo, FORK);
	pthread_mutex_lock(philo->righthand_fork);
	wprintf(philo, FORK);
	get_curr_time_abs_usec(&philo->last_meal_abs_usec);
	wprintf(philo, EAT);
	usleep(philo->time_to_eat_ms * 1000);
	philo->meals_had++;
	return (unlock_the_locks(philo->lefthand_fork, philo->righthand_fork));
}

void	doze_off(t_philo_data *philo)
{
	wprintf(philo, SLEEP);
	usleep(philo->time_to_sleep_ms * 1000);
	return ;
}

void	think(t_philo_data *philo)
{
	wprintf(philo, THINK);
	usleep(50);
	return ;
}

void	*dine(void *arg)
{
	t_philo_data	*philo;

	philo = (t_philo_data *)arg;
	while (dinner_must_continue(philo))
	{
		usleep(50);
		eat(philo);
		doze_off(philo);
		think(philo);
	}
	return (NULL);
}
