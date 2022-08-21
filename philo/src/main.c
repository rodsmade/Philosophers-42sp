/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:10:21 by roaraujo          #+#    #+#             */
/*   Updated: 2022/08/21 12:14:30 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	monitor_threads(t_philo_data **philos, t_common_data *common);

int	main(int argc, char *argv[])
{
	t_common_data	common;
	t_philo_data	*philos;

	if (!passes_arg_check(argc, argv, &common))
		return (-1);
	initialise_data(&philos, &common);
	create_threads(&philos);
	monitor_threads(&philos, &common);
	join_threads(&philos);
	free_up_memory(&philos);
	return (0);
}

void	monitor_threads(t_philo_data **philos, t_common_data *common)
{
	int				i;
	t_philo_data	philo;

	i = -1;
	while (true)
	{
		i = (i + 1) % common->nb_of_philos;
		philo = (*philos)[i];
		if (!common->infinite_dinner && all_philos_ate_enough(philos, common))
			break ;
		if (time_elapsed_ms(philo.last_meal_abs_usec) >= common->time_to_die_ms
			&& dinner_must_continue(&philo))
		{
			write_var(&common->halt_execution, &common->halt_mutex, true);
			wprintf(&philo, DIE);
			break ;
		}
		usleep(450);
	}
}
