/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:10:32 by roaraujo          #+#    #+#             */
/*   Updated: 2022/08/17 16:53:57 by roaraujo         ###   ########.fr       */
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

void	free_up_memory(t_philo_data **philosophers, int philos_number)
{
	int	i;

	i = -1;
	while (++i < philos_number)
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
