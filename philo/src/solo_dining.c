/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solo_dining.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 10:18:21 by roaraujo          #+#    #+#             */
/*   Updated: 2022/08/21 12:16:02 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*dine_solo(t_philo_data *one_philo)
{
	int	ts;

	ts = time_elapsed_ms(one_philo->common->pgm_started_abs_usec);
	printf("%s%d %d %s%s\n", LILAC, ts, one_philo->id, FORK, RESET);
	usleep(one_philo->time_to_die_ms * 1000);
	ts = time_elapsed_ms(one_philo->common->pgm_started_abs_usec);
	return (NULL);
}
