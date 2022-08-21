/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:10:32 by roaraujo          #+#    #+#             */
/*   Updated: 2022/08/21 14:44:51 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	unlock_the_locks(pthread_mutex_t *left_fork,
	pthread_mutex_t *right_fork)
{
	if (left_fork)
		pthread_mutex_unlock(left_fork);
	if (right_fork)
		pthread_mutex_unlock(right_fork);
	return ;
}

void	ft_free_ptr(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_up_memory(t_philo_data **philosophers)
{
	int	i;

	i = -1;
	while (++i < (*philosophers)[0].common->nb_of_philos)
	{
		pthread_mutex_destroy((*philosophers)[i].this_fork);
		ft_free_ptr((void *)&(*philosophers)[i].this_fork);
		pthread_mutex_destroy((*philosophers)[i].last_meal_mutex);
		ft_free_ptr((void *)&(*philosophers)[i].last_meal_mutex);
		pthread_mutex_destroy((*philosophers)[i].meals_had_mutex);
		ft_free_ptr((void *)&(*philosophers)[i].meals_had_mutex);
		ft_free_ptr((void *)&(*philosophers)[i].thread);
	}
	pthread_mutex_destroy(&((*philosophers)[0].common->printf_mutex));
	pthread_mutex_destroy(&((*philosophers)[0].common->halt_mutex));
	ft_free_ptr((void *)philosophers);
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
