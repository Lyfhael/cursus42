/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 04:17:29 by hateisse          #+#    #+#             */
/*   Updated: 2023/05/29 00:26:46 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	has_eaten_enough(t_philos *philos)
{
	if (philos->philo_params.nb_meals == DISABLED)
		return (false);
	else if (philos->nb_meals >= philos->philo_params.nb_meals)
		return (true);
	return (false);
}

bool	philo_eat(t_philos *philos)
{
	pthread_mutex_lock(philos->locks.lprint);
	if (has_eaten_enough(philos) || is_dead(philos))
		return (pthread_mutex_unlock(philos->locks.lprint), false);
	pthread_mutex_unlock(philos->locks.lprint);
	if (philos->left == philos)
		return (more_accurate_usleep(1), philo_eat(philos));
	if (take_forks(philos) == false)
		return (false);
	philos->action = EATING;
	if (!print_current_action(philos))
		return (lay_forks(philos), false);
	if (philos->philo_params.nb_meals != DISABLED)
		philos->nb_meals += 1;
	pthread_mutex_lock(philos->locks.lmeal_ts);
	philos->last_meal_ts = current_ms_timestamp();
	pthread_mutex_unlock(philos->locks.lmeal_ts);
	more_accurate_usleep(philos->philo_params.time_to_eat);
	lay_forks(philos);
	return (true);
}
