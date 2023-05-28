/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 01:02:56 by hateisse          #+#    #+#             */
/*   Updated: 2023/05/27 06:51:57 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	philo_atol(const char *nptr, long max_value, int *errno)
{
	int		sign;
	long	res;

	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
		if (*(nptr++) == '-')
			sign = -1;
	res = 0;
	while (ft_isdigit(*nptr) && res <= max_value)
		res = res * 10 + (*(nptr++) - 48);
	if (*nptr && ft_isdigit(*nptr))
		*errno = ERMAXVAL;
	else if (*nptr && !ft_isdigit(*nptr))
		*errno = ERNONDIGIT;
	return (res * sign);
}

int	check_argument_validity(char *arg, int argno, int *errno)
{
	int	result;

	result = 0;
	if (*errno)
		return (0);
	if (*arg == '-')
		*errno = ERNEGVAL;
	else if (!*arg)
		*errno = EREMPTYVAL;
	else
		result = philo_atol(arg, INT_MAX, errno);
	if (result == 0 && !*errno && argno == 1)
		*errno = ERZEROVAL;
	if (*errno)
		print_error(*errno, arg);
	return (result);
}

int	determine_time_to_think(t_philo_params *philo_params)
{
	int	time_to_eat;
	int	time_to_sleep;

	time_to_eat = philo_params->time_to_eat;
	time_to_sleep = philo_params->time_to_sleep;
	if (philo_params->nb_philos % 2 == 0)
		return (0);
	if (time_to_eat == time_to_sleep)
		return (time_to_sleep);
	else if (time_to_eat > time_to_sleep)
		return (time_to_eat + time_to_sleep);
	return (0);
}

bool	parse_arguments(int ac, char **av, t_philo_params *philo_params)
{
	int	errno;

	errno = 0;
	if (ac != 5 && ac != 6)
		return (print_usage(), false);
	philo_params->nb_philos = check_argument_validity(av[1], 1, &errno);
	philo_params->time_to_die = check_argument_validity(av[2], 2, &errno);
	philo_params->time_to_eat = check_argument_validity(av[3], 3, &errno);
	philo_params->time_to_sleep = check_argument_validity(av[4], 4, &errno);
	philo_params->time_to_think = determine_time_to_think(philo_params);
	if (ac == 6)
		philo_params->nb_meals = check_argument_validity(av[5], 5, &errno);
	else
		philo_params->nb_meals = DISABLED;
	if (errno)
		return (false);
	return (true);
}
