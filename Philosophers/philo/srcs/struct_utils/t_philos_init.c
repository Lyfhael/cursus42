/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philos_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 06:41:06 by hateisse          #+#    #+#             */
/*   Updated: 2023/06/01 20:28:57 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	init_philos(t_philos **philos, t_philo_params pparams)
{
	int					i;
	t_philos			*new;
	pthread_mutex_t		*print;

	print = ft_calloc(1, sizeof(pthread_mutex_t));
	*philos = 0;
	if (!print)
		return (print_error(ERMALLOC, NULL), false);
	i = 0;
	if (pthread_mutex_init(print, NULL))
		return (free(print), print_error(ERMUTINIT, NULL), false);
	while (i < pparams.nb_philos)
	{
		new = philos_ls_new(i++, pparams);
		if (!new)
		{
			free_mutex(print);
			return (print_error(ERLSNEW, NULL), philos_ls_free(philos), false);
		}
		new->locks.lprint = print;
		philos_ls_addback(philos, new);
	}
	(*philos)->left = philos_ls_last(*philos);
	philos_ls_last(*philos)->right = *philos;
	return (true);
}
