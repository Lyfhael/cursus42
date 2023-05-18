/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 04:17:48 by hateisse          #+#    #+#             */
/*   Updated: 2023/05/16 08:35:18 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	philo_think(t_philos *philos)
{
	philos->action = THINKING;
	if (!print_current_action(philos))
		return (false);
	return (true);
}
