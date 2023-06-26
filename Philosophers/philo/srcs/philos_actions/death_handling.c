/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:32:26 by hateisse          #+#    #+#             */
/*   Updated: 2023/06/01 20:39:19 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	has_someone_died(t_philos *philos)
{
	int			i;

	i = philos->philo_params.nb_philos;
	while (i--)
	{
		pthread_mutex_lock(philos->locks.lstate);
		if (philos->state == DEAD)
			return (pthread_mutex_unlock(philos->locks.lstate), true);
		pthread_mutex_unlock(philos->locks.lstate);
		philos = philos->right;
	}
	return (false);
}

bool	has_exited(t_philos *philos)
{
	pthread_mutex_lock(philos->locks.lexit);
	if (philos->thread_has_exit)
		return (pthread_mutex_unlock(philos->locks.lexit), true);
	pthread_mutex_unlock(philos->locks.lexit);
	return (false);
}

void	declare_death(t_philos *philos, t_ts current_ts)
{
	if (!has_someone_died(philos))
	{
		if (philos->start_ts == 0)
			printf("%s%d%s\t", LGREY, 0, NC);
		else
			printf("%s%llu%s\t", LGREY, (current_ts - philos->start_ts), NC);
		printf("%d died\n", philos->id);
	}
	pthread_mutex_lock(philos->locks.lstate);
	philos->state = DEAD;
	pthread_mutex_unlock(philos->locks.lstate);
}

bool	is_dead(t_philos *philos)
{
	int		time_to_die;
	t_ts	current_ts;

	pthread_mutex_lock(philos->locks.lstate);
	if (philos->state == STARTING || has_exited(philos))
		return (pthread_mutex_unlock(philos->locks.lstate), false);
	else if (philos->state == DEAD)
		return (pthread_mutex_unlock(philos->locks.lstate), true);
	pthread_mutex_unlock(philos->locks.lstate);
	time_to_die = philos->philo_params.time_to_die;
	current_ts = current_ms_timestamp();
	pthread_mutex_lock(philos->locks.lmeal_ts);
	if (current_ts - philos->last_meal_ts > (t_ts)time_to_die)
	{
		pthread_mutex_unlock(philos->locks.lmeal_ts);
		declare_death(philos, current_ts);
		return (true);
	}
	pthread_mutex_unlock(philos->locks.lmeal_ts);
	return (false);
}
