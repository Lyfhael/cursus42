/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:39:19 by hateisse          #+#    #+#             */
/*   Updated: 2023/06/26 06:57:34 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	init_mutex(pthread_mutex_t **mutex)
{
	*mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!*mutex)
		return (false);
	if (pthread_mutex_init(*mutex, NULL))
		return (free(*mutex), false);
	return (true);
}

void	free_mutex(pthread_mutex_t *mutex)
{
	pthread_mutex_destroy(mutex);
	free(mutex);
}

bool	init_philos_mutex(t_philos *new)
{
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*lstate;
	pthread_mutex_t	*lexit;
	pthread_mutex_t	*lmeal;

	if (!init_mutex(&lfork))
		return (false);
	if (!init_mutex(&lstate))
		return (free_mutex(lfork), false);
	if (!init_mutex(&lexit))
		return (free_mutex(lfork), free_mutex(lstate), false);
	if (!init_mutex(&lmeal))
	{
		free_mutex(lexit);
		return (free_mutex(lstate), free_mutex(lfork), false);
	}
	new->locks.lfork = lfork;
	new->locks.lstate = lstate;
	new->locks.lexit = lexit;
	new->locks.lmeal_ts = lmeal;
	return (true);
}
