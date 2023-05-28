/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 01:56:31 by hateisse          #+#    #+#             */
/*   Updated: 2023/05/28 18:28:19 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	wait_all_threads_started(t_philos *philos)
{
	int	all_threads_initialized;

	all_threads_initialized = PENDING;
	while (all_threads_initialized != SUCCESS)
	{
		all_threads_initialized = all_threads_started(philos);
		if (all_threads_initialized == ERROR)
		{
			pthread_mutex_lock(philos->locks.lexit);
			philos->thread_has_exit = true;
			pthread_mutex_unlock(philos->locks.lexit);
			return (false);
		}
		else if (all_threads_initialized != SUCCESS)
			usleep(50);
	}
	return (true);
}

bool	philo_threads_staging_area(t_philos *philos)
{
	if (wait_all_threads_started(philos) == false)
		return (false);
	pthread_mutex_lock(philos->locks.lprint);
	philos->start_ts = current_ms_timestamp();
	pthread_mutex_unlock(philos->locks.lprint);
	if (philos->id == 0
		|| (philos->philo_params.nb_philos % 2 == 0 && philos->id % 2 == 0))
		;
	else if (philos->id % 2 != 0)
		more_accurate_usleep(philos->philo_params.time_to_eat);
	else
		more_accurate_usleep(philos->philo_params.time_to_eat * 2);
	return (true);
}

void	*philo_routine(void *vphilos)
{
	t_philos			*philos;

	philos = vphilos;
	if (philo_threads_staging_area(philos) == false)
		return (NULL);
	pthread_mutex_lock(philos->locks.lstate);
	philos->state = ALIVE;
	pthread_mutex_unlock(philos->locks.lstate);
	while (1)
	{
		if (!philo_next_action(philos))
			break ;
	}
	pthread_mutex_lock(philos->locks.lexit);
	philos->thread_has_exit = true;
	pthread_mutex_unlock(philos->locks.lexit);
	return (NULL);
}

int	all_threads_started(t_philos *philos)
{
	int		i;

	i = philos->philo_params.nb_philos;
	while (i--)
	{
		pthread_mutex_lock(philos->locks.lstate);
		if (philos->state == FAILED_TO_START)
			return (pthread_mutex_unlock(philos->locks.lstate), ERROR);
		else if (philos->state == STARTING)
			return (pthread_mutex_unlock(philos->locks.lstate), PENDING);
		pthread_mutex_unlock(philos->locks.lstate);
		philos = philos->right;
	}
	return (SUCCESS);
}

bool	launch_philos(t_philos *philos, t_philo_params philo_params)
{
	pthread_t	new_thread;

	new_thread = 0;
	pthread_mutex_lock(philos->locks.lprint);
	while (philo_params.nb_philos--)
	{
		pthread_mutex_lock(philos->locks.lmeal_ts);
		philos->last_meal_ts = current_ms_timestamp();
		pthread_mutex_unlock(philos->locks.lmeal_ts);
		if (pthread_create(&new_thread, NULL, &philo_routine, philos))
			return (routine_after_thread_failure(philos), false);
		else if (pthread_detach(new_thread))
			return (routine_after_thread_failure(philos), false);
		else
		{
			pthread_mutex_lock(philos->locks.lstate);
			philos->state = READY;
			pthread_mutex_unlock(philos->locks.lstate);
		}
		philos = philos->right;
	}
	usleep(100);
	pthread_mutex_unlock(philos->locks.lprint);
	return (true);
}
