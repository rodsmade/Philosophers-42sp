/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers-dinner.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:10:21 by roaraujo          #+#    #+#             */
/*   Updated: 2022/08/21 10:04:36 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*dine(void *arg);
void	eat(t_philo_data *philo);
void	doze_off(t_philo_data *philo);
void	think(t_philo_data *philo);
int		all_philos_ate_enough(t_philo_data **philos, t_common_data *common);
void	create_threads(t_philo_data **philos);
void	join_threads(t_philo_data **philos);
void	monitor_threads(t_philo_data **philos, t_common_data *common);

int	main(int argc, char *argv[])
{
	t_common_data	common;
	t_philo_data	*philos;

	if (!passes_arg_check(argc, argv, &common))
		return (-1);
	initialise_data(&philos, &common);
	if (common.nb_of_philos == 1)
		return (one_philo(&philos[0]));
	create_threads(&philos);
	monitor_threads(&philos, &common);
	join_threads(&philos);
	free_up_memory(&philos);
	return (0);
}

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

bool	dinner_must_continue(t_philo_data *philo)
{
	if (philo->common->infinite_dinner)
	{
		if (!must_halt(philo))
			return (true);
		else
			return (false);
	}
	else
	{
		if (philo->meals_had < philo->common->nb_of_meals && !must_halt(philo))
			return (true);
		else
			return (false);
	}
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

int	all_philos_ate_enough(t_philo_data **philos, t_common_data *common)
{
	int	i;
	int	full_philos;

	full_philos = 0;
	i = -1;
	while (++i < common->nb_of_philos)
	{
		if ((*philos)[i].meals_had >= common->nb_of_meals)
			full_philos++;
	}
	return (full_philos == common->nb_of_philos);
}

void	monitor_threads(t_philo_data **philos, t_common_data *common)
{
	int	i;

	i = -1;
	while (true)
	{
		i = (i + 1) % common->nb_of_philos;
		if (!common->infinite_dinner && all_philos_ate_enough(philos, common))
			break ;
		if (dinner_must_continue(&(*philos)[i])
			&& time_elapsed_ms((*philos)[i].last_meal_abs_usec) > common->time_to_die_ms)
		{
			// printf("ué n entrou?\n");
			write_var(&common->halt_execution, &common->halt_mutex, true);
			wprintf(&(*philos)[i], DIE);
			break ;
		}
		usleep(450);
	}
}

void	create_threads(t_philo_data **philos)
{
	int	i;
	int	nb_of_philos;

	nb_of_philos = (*philos)[0].common->nb_of_philos;
	i = -1;
	while (++i < nb_of_philos)
		pthread_create((*philos)[i].thread, NULL, &dine, (void *)((*philos) + i));
	return ;
}

void	join_threads(t_philo_data **philos)
{
	int	i;
	int	nb_of_philos;

	nb_of_philos = (*philos)[0].common->nb_of_philos;
	i = -1;
	while (++i < nb_of_philos)
		pthread_join(*(*philos)[i].thread, NULL);
	return ;
}
