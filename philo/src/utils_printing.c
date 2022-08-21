/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:48:02 by roaraujo          #+#    #+#             */
/*   Updated: 2022/08/21 12:30:07 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*s_s1;
	unsigned char	*s_s2;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	s_s1 = (unsigned char *)s1;
	s_s2 = (unsigned char *)s2;
	while (s_s1[i] || s_s2[i])
	{
		if (s_s1[i] != s_s2[i])
			return (s_s1[i] - s_s2[i]);
		i++;
	}
	return (0);
}

void	wprintf(t_philo_data *philo, char *action)
{
	int	tstamp_ms;

	pthread_mutex_lock(&philo->common->printf_mutex);
	tstamp_ms = time_elapsed_ms(philo->common->pgm_started_abs_usec);
	if (!ft_strcmp(action, FORK) && !must_halt(philo))
		printf("%s%d %d %s%s\n", LILAC, tstamp_ms, philo->id, FORK, RESET);
	if (!ft_strcmp(action, EAT) && !must_halt(philo))
		printf("%s%d %d %s%s\n", LYELLOW, tstamp_ms, philo->id, EAT, RESET);
	if (!ft_strcmp(action, THINK) && !must_halt(philo))
		printf("%s%d %d %s%s\n", ORANGE, tstamp_ms, philo->id, THINK, RESET);
	if (!ft_strcmp(action, SLEEP) && !must_halt(philo))
		printf("%s%d %d %s%s\n", BBLUE, tstamp_ms, philo->id, SLEEP, RESET);
	if (!ft_strcmp(action, DIE) && philo->common->first_death)
	{
		philo->common->first_death = false;
		printf("%s%d %d %s%s\n", BHMAGENTA, tstamp_ms, philo->id, DIE, RESET);
	}
	pthread_mutex_unlock(&philo->common->printf_mutex);
	return ;
}
