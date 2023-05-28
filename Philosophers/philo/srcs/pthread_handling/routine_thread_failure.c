/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_thread_failure.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:12:23 by hateisse          #+#    #+#             */
/*   Updated: 2023/05/28 19:53:33 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	routine_after_thread_failure(t_philos *philos)
{
	pthread_mutex_lock(philos->locks.lstate);
	philos->state = READY;
	pthread_mutex_unlock(philos->locks.lstate);
	pthread_mutex_lock(philos->locks.lexit);
	philos->thread_has_exit = true;
	pthread_mutex_unlock(philos->locks.lexit);
	printf("A philo has escaped! (pthread launch failed)\n");
	while (all_threads_exited(philos) == false)
		usleep(50);
	pthread_mutex_unlock(philos->locks.lprint);
	philos_ls_free(&philos);
}
