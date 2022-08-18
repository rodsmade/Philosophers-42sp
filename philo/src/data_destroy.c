/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:10:32 by roaraujo          #+#    #+#             */
/*   Updated: 2022/08/18 10:25:44 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
		ft_free_ptr((void *)&(*philosophers)[i].thread);
		ft_free_ptr((void *)&(*philosophers)[i].this_fork);
	}
	pthread_mutex_destroy(&((*philosophers)[0].common->printf_mutex));
	pthread_mutex_destroy(&((*philosophers)[0].common->halt_mutex));
	ft_free_ptr((void *)philosophers);
	return ;
}
