/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 04:46:38 by hateisse          #+#    #+#             */
/*   Updated: 2023/05/16 08:21:33 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	philo_escape(t_philos *philos)
{
	philos->action = ESCAPING;
	if (!print_current_action(philos))
		return (false);
	return (true);
}
