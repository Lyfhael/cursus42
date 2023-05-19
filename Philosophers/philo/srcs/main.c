/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:20:01 by hateisse          #+#    #+#             */
/*   Updated: 2023/05/19 23:41:27 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	have_everyone_exited(t_philos *philos)
{
	int			i;

	i = philos->philo_params.nb_philos;
	while (i--)
	{
		pthread_mutex_lock(philos->locks.lexit);
		if (!philos->thread_has_exit)
			return (pthread_mutex_unlock(philos->locks.lexit), false);
		pthread_mutex_unlock(philos->locks.lexit);
		philos = philos->right;
	}
	return (true);
}

void	loop_check_program_can_end(t_philos *philos, t_philo_params pparams)
{
	while (1)
	{
		usleep(2 * 1000);
		pthread_mutex_lock(philos->locks.lprint);
		if (has_someone_died(philos) || is_dead(philos))
		{
			pthread_mutex_unlock(philos->locks.lprint);
			while (1)
			{
				usleep(2 * 1000);
				if (have_everyone_exited(philos))
					return ;
			}
		}
		pthread_mutex_unlock(philos->locks.lprint);
		if (pparams.nb_meals != DISABLED && have_everyone_exited(philos))
			return ;
		philos = philos->right;
	}
}

int	main(int argc, char **argv)
{
	t_philo_params	philo_params;
	t_philos		*philos;

	ft_bzero(&philos, sizeof(t_philos *));
	if (parse_arguments(argc, argv, &philo_params) == false)
		return (FAILURE);
	else if (init_philos(&philos, philo_params) == false)
		return (FAILURE);
	else if (launch_philos(philos, philo_params) == false)
		return (FAILURE);
	loop_check_program_can_end(philos, philo_params);
	philos_ls_free(&philos);
	return (SUCCESS);
}
