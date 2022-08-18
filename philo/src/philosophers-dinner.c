/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers-dinner.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:10:21 by roaraujo          #+#    #+#             */
/*   Updated: 2022/08/18 10:11:13 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat(t_philo_data *philo)
{
	if (!must_halt(philo))
	{
		pthread_mutex_lock(philo->lefthand_fork);
		wprintf(philo, FORK);
		if (must_halt(philo))
			return (unlock_locks(philo->lefthand_fork, NULL));
	}
	if (!must_halt(philo))
	{
		pthread_mutex_lock(philo->righthand_fork);
		wprintf(philo, FORK);
		if (must_halt(philo))
			return (unlock_locks(philo->lefthand_fork, philo->righthand_fork));
	}
	else
		return (unlock_locks(philo->lefthand_fork, NULL));
	decide_sleep_time(philo);
	return (unlock_locks(philo->lefthand_fork, philo->righthand_fork));
}

void	doze_off(t_philo_data *philo)
{
	wprintf(philo, SLEEP);
	if (i_should_die_before_i_wake(philo, philo->time_to_sleep_ms))
		return ;
	usleep(philo->time_to_sleep_ms * 1000);
	wprintf(philo, THINK);
	return ;
}

void	*dine(void *arg)
{
	t_philo_data	*philo;

	philo = (t_philo_data *)arg;
	while (((!philo->infinite_dinner && (philo->meals_had < philo->nb_of_meals))
			&& !must_halt(philo))
		|| (philo->infinite_dinner && !must_halt(philo)))
	{
		if (!must_halt(philo))
			eat(philo);
		if (!must_halt(philo))
			doze_off(philo);
	}
	return (NULL);
}

int	one_philo(t_philo_data *one_philo)
{
	int	ts;

	ts = get_timestamp_ms(one_philo->pgm_started_abs_usec);
	printf("%s%d %d %s%s\n", LILAC, ts, one_philo->id, FORK, COLOUR_RESET);
	usleep(one_philo->time_to_die_ms * 1000);
	ts = get_timestamp_ms(one_philo->pgm_started_abs_usec);
	printf("%s%d %d %s%s\n", BHMAGENTA, ts, one_philo->id, DIE, COLOUR_RESET);
	return (1);
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
	free_up_memory(&philos, common.nb_of_philos);
	return (0);
}
