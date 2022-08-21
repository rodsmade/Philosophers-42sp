/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_ancillary_funcs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 10:15:31 by roaraujo          #+#    #+#             */
/*   Updated: 2022/08/21 19:22:38 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	must_halt(t_philo_data *philo)
{
	return (read_var((int *) &philo->common->halt_execution,
			&philo->common->halt_mutex));
}

int	dinner_must_continue(t_philo_data *philo)
{
	if (philo->common->infinite_dinner)
	{
		if (!must_halt(philo))
			return (TRUE);
		else
			return (FALSE);
	}
	else
	{
		if (philo->meals_had <= philo->common->nb_of_meals && !must_halt(philo))
			return (TRUE);
		else
			return (FALSE);
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
		if (read_var(&(*philos)[i].meals_had, (*philos)[i].meals_had_mutex)
			>= common->nb_of_meals)
			full_philos++;
	}
	return (full_philos == common->nb_of_philos);
}
