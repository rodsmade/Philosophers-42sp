/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers-dinner.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:10:21 by roaraujo          #+#    #+#             */
/*   Updated: 2022/08/18 11:18:31 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat(t_philo_data *philo)
{
	pthread_mutex_lock(philo->lefthand_fork);
	wprintf(philo, FORK);
	pthread_mutex_lock(philo->righthand_fork);
	wprintf(philo, FORK);
	decide_sleep_time(philo);
	return (unlock_the_locks(philo->lefthand_fork, philo->righthand_fork));
}

void	doze_off(t_philo_data *philo)
{
	wprintf(philo, SLEEP);
	usleep(philo->time_to_sleep_ms * 1000);
	wprintf(philo, THINK);
	return ;
}

void	*dine(void *arg)
{
	t_philo_data	*philo;

	philo = (t_philo_data *)arg;
	(void) philo;
	return (NULL);
}

int	main(int argc, char *argv[])
{
	int				i;
	t_common_data	common;
	t_philo_data	*philos;

	if (!passes_arg_check(argc, argv, &common))
		return (-1);
	initialise_data(&philos, &common);
	if (common.nb_of_philos == 1)
		return (one_philo(&philos[0]));
	i = -1;
	while (++i < common.nb_of_philos)
		pthread_create(philos[i].thread, NULL, &dine, (void *)(philos + i));
	i = -1;
	while (++i < common.nb_of_philos)
		pthread_join(*philos[i].thread, NULL);
	free_up_memory(&philos);
	return (0);
}
