/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:48:02 by roaraujo          #+#    #+#             */
/*   Updated: 2022/08/16 10:36:55 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	get_curr_time_abs_usec(time_t *current_time)
{
	struct timeval	*tv;

	tv = malloc(sizeof(*tv));
	if (gettimeofday(tv, NULL) != 0)
	{
		printf("Error getting timestamp\n");
		*current_time = 0;
	}
	else
		*current_time = tv->tv_sec * 1000000 + tv->tv_usec;
	ft_free_ptr((void *)&tv);
	return ;
}

int	get_timestamp_ms(unsigned long int pgm_started_abs_usec)
{
	int		timestamp_ms;
	time_t	current_time_abs_usec;

	get_curr_time_abs_usec(&current_time_abs_usec);
	timestamp_ms = (current_time_abs_usec - pgm_started_abs_usec) / 1000;
	return (timestamp_ms);
}
