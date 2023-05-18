/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 01:56:31 by hateisse          #+#    #+#             */
/*   Updated: 2023/05/18 18:59:03 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_ts	current_ms_timestamp(void)
{
	struct timeval		tv;
	unsigned long long	seconds;
	unsigned long long	microseconds;

	if (gettimeofday(&tv, NULL))
		return (0);
	seconds = (unsigned long long)(tv.tv_sec);
	microseconds = (unsigned long long)(tv.tv_usec);
	return ((seconds * 1000) + (microseconds / 1000));
}

void	*philo_routine(void *vphilos)
{
	t_philos			*philos;

	philos = vphilos;
	pthread_mutex_lock(philos->locks.lstate);
	philos->state = ALIVE;
	pthread_mutex_unlock(philos->locks.lstate);
	while (1)
		if (!philo_next_action(philos))
			break ;
	pthread_mutex_lock(philos->locks.lexit);
	philos->thread_has_exit = true;
	pthread_mutex_unlock(philos->locks.lexit);
	return (NULL);
}

bool	launch_philos(t_philos *philos, t_philo_params philo_params)
{
	pthread_t	new_thread;

	new_thread = 0;
	while (philo_params.nb_philos--)
	{
		pthread_mutex_lock(philos->locks.lmeal_ts);
		philos->last_meal_ts = current_ms_timestamp();
		pthread_mutex_unlock(philos->locks.lmeal_ts);
		philos->start_ts = current_ms_timestamp();
		if (pthread_create(&new_thread, NULL, &philo_routine, philos))
			printf("A philo has escaped! (pthread_create() failed)\n");
		else
			pthread_detach(new_thread);
		philos = philos->right;
	}
	return (true);
}
