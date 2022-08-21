/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_ancillary_funcs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 10:15:31 by roaraujo          #+#    #+#             */
/*   Updated: 2022/08/21 12:24:42 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	must_halt(t_philo_data *philo)
{
	return (read_var(&philo->common->halt_execution,
			&philo->common->halt_mutex));
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
