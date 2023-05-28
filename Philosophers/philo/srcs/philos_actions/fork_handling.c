/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 08:13:54 by hateisse          #+#    #+#             */
/*   Updated: 2023/05/27 04:06:49 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	take_right_fork(t_philos *philos)
{
	pthread_mutex_lock(philos->locks.lfork);
	philos->action = TAKING_RIGHT_FORK;
	if (!print_current_action(philos))
	{
		pthread_mutex_unlock(philos->locks.lfork);
		return (false);
	}
	return (true);
}

bool	take_left_fork(t_philos *philos)
{
	pthread_mutex_lock(philos->left->locks.lfork);
	philos->action = TAKING_LEFT_FORK;
	if (!print_current_action(philos))
	{
		pthread_mutex_unlock(philos->left->locks.lfork);
		return (false);
	}
	return (true);
}

bool	take_forks(t_philos *philos)
{
	if (philos->id % 2 == 0)
	{
		if (take_left_fork(philos) == false)
			return (false);
		if (take_right_fork(philos) == false)
			return (pthread_mutex_unlock(philos->left->locks.lfork), false);
	}
	else
	{
		if (take_right_fork(philos) == false)
			return (false);
		if (take_left_fork(philos) == false)
			return (pthread_mutex_unlock(philos->locks.lfork), false);
	}
	return (true);
}

void	lay_forks(t_philos *philos)
{
	pthread_mutex_unlock(philos->left->locks.lfork);
	pthread_mutex_unlock(philos->locks.lfork);
}
