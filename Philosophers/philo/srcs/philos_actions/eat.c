/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 04:17:29 by hateisse          #+#    #+#             */
/*   Updated: 2023/05/18 05:58:39 by hateisse         ###   ########.fr       */
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
		return (usleep(1 * 4000), philo_eat(philos));
	philos->action = TAKING_FORK;
	take_forks(philos);
	if (!print_current_action(philos))
		return (lay_forks(philos), false);
	philos->action = EATING;
	pthread_mutex_lock(philos->locks.lmeal_ts);
	pthread_mutex_unlock(philos->locks.lmeal_ts);
	if (!print_current_action(philos))
		return (lay_forks(philos), false);
	philos->last_meal_ts = current_ms_timestamp();
	usleep(philos->philo_params.time_to_eat * 1000);
	lay_forks(philos);
	if (philos->philo_params.nb_meals != DISABLED)
		philos->nb_meals += 1;
	return (true);
}
