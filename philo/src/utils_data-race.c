/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_data-race.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:35:48 by roaraujo          #+#    #+#             */
/*   Updated: 2022/08/17 17:29:37 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	must_halt(t_philo_data *philosopher)
{
	int	temp;

	pthread_mutex_lock(&philosopher->common->halt_mutex);
	temp = *philosopher->halt;
	pthread_mutex_unlock(&philosopher->common->halt_mutex);
	return (temp);
}

void	write_halt(bool *var, pthread_mutex_t *mutex, bool status)
{
	pthread_mutex_lock(mutex);
	*var = status;
	pthread_mutex_unlock(mutex);
}
