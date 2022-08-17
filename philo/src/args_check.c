/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:11:01 by roaraujo          #+#    #+#             */
/*   Updated: 2022/08/17 17:13:21 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	copy_args(char *argv[], t_common_data *common)
{
	common->nb_of_philos = ft_atoli(argv[1]);
	common->time_to_die_ms = ft_atoli(argv[2]);
	common->time_to_eat_ms = ft_atoli(argv[3]);
	common->time_to_sleep_ms = ft_atoli(argv[4]);
	if (argv[5])
	{
		common->nb_of_meals = ft_atoli(argv[5]);
		common->infinite_dinner = false;
	}
	else
	{
		common->nb_of_meals = 0;
		common->infinite_dinner = true;
	}
	return ;
}

bool	passes_arg_check(int argc, char *argv[], t_common_data *common)
{
	int			i;
	long int	argv_li;

	if (argc != 5 && argc != 6)
		return (false);
	i = 0;
	while (++i < argc)
	{
		argv_li = ft_atoli(argv[i]);
		if (!ft_isnumeric_s(argv[i]) || (argv_li > INT_MAX || argv_li < 0))
			return (false);
	}
	copy_args(argv, common);
	return (true);
}
