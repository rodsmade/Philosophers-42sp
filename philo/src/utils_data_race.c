/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_data-race.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:35:48 by roaraujo          #+#    #+#             */
/*   Updated: 2022/08/19 10:04:06 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	read_var(bool *var, pthread_mutex_t *mutex)
{
	int	temp;

	pthread_mutex_lock(mutex);
	temp = *var;
	pthread_mutex_unlock(mutex);
	return (temp);
}

void	write_var(bool *var, pthread_mutex_t *mutex, bool status)
{
	pthread_mutex_lock(mutex);
	*var = status;
	pthread_mutex_unlock(mutex);
}
