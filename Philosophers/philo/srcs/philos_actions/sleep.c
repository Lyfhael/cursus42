/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 04:18:42 by hateisse          #+#    #+#             */
/*   Updated: 2023/05/16 08:51:07 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	philo_sleep(t_philos *philos)
{
	philos->action = SLEEPING;
	if (!print_current_action(philos))
		return (false);
	usleep(philos->philo_params.time_to_sleep * 1000);
	return (true);
}
