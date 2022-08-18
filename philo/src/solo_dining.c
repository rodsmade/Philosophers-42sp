/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solo_dining.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 10:18:21 by roaraujo          #+#    #+#             */
/*   Updated: 2022/08/18 10:58:22 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	one_philo(t_philo_data *one_philo)
{
	int	ts;

	ts = get_timestamp_ms(one_philo->pgm_started_abs_usec);
	printf("%s%d %d %s%s\n", LILAC, ts, one_philo->id, FORK, RESET);
	usleep(one_philo->time_to_die_ms * 1000);
	ts = get_timestamp_ms(one_philo->pgm_started_abs_usec);
	printf("%s%d %d %s%s\n", BHMAGENTA, ts, one_philo->id, DIE, RESET);
	return (0);
}
