/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:11:01 by roaraujo          #+#    #+#             */
/*   Updated: 2022/08/20 21:27:27 by roaraujo         ###   ########.fr       */
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
		common->nb_of_meals = -42;
		common->infinite_dinner = true;
	}
	return ;
}

bool	print_argc_err(void)
{
	printf("%s❌ Must pass in the following arguments in order "
		"(last one is optional):%s\n"
		"\t%snumber_of_philosophers%s, \n"
		"\t%stime_to_die (ms)%s, \n"
		"\t%stime_to_eat (ms)%s, \n"
		"\t%stime_to_sleep (ms)%s, \n"
		"\t%s[number_of_times_each_philosopher_must_eat (ms)]%s.\n",
		BHMAGENTA, RESET, BHBLUE, RESET, BHBLUE, RESET, BHBLUE, RESET,
		BHBLUE, RESET, BLUE, RESET);
	return (false);
}

bool	print_numeric_err(void)
{
	printf("%s❌ Arguments must be numeric between 0 and INT_MAX!%s\n",
		BHMAGENTA, RESET);
	return (false);
}

bool	passes_arg_check(int argc, char *argv[], t_common_data *common)
{
	int			i;
	long int	argv_li;

	if (argc != 5 && argc != 6)
		return (print_argc_err());
	i = 0;
	while (++i < argc)
	{
		argv_li = ft_atoli(argv[i]);
		if (!ft_isnumeric_s(argv[i]) || (argv_li > INT_MAX || argv_li < 0))
			return (print_numeric_err());
	}
	copy_args(argv, common);
	return (true);
}
