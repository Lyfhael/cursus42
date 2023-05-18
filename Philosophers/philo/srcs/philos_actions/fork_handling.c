/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 08:13:54 by hateisse          #+#    #+#             */
/*   Updated: 2023/05/16 08:15:44 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_philos *philos)
{
	if (philos->id % 2 == 0)
	{
		pthread_mutex_lock(philos->left->locks.lfork);
		pthread_mutex_lock(philos->locks.lfork);
	}
	else
	{
		pthread_mutex_lock(philos->locks.lfork);
		pthread_mutex_lock(philos->left->locks.lfork);
	}
}

void	lay_forks(t_philos *philos)
{
	pthread_mutex_unlock(philos->left->locks.lfork);
	pthread_mutex_unlock(philos->locks.lfork);
}
