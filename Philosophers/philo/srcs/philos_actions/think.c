/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 04:17:48 by hateisse          #+#    #+#             */
/*   Updated: 2023/05/27 22:10:08 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	philo_think(t_philos *philos)
{
	philos->action = THINKING;
	if (!print_current_action(philos))
		return (false);
	if (philos->philo_params.time_to_think)
		more_accurate_usleep(philos->philo_params.time_to_think);
	return (true);
}
