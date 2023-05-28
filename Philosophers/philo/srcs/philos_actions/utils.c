/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 04:39:14 by hateisse          #+#    #+#             */
/*   Updated: 2023/05/27 22:08:32 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	more_accurate_usleep(t_milliseconds time_to_sleep)
{
	t_ts	time_start;

	time_start = current_ms_timestamp();
	while ((current_ms_timestamp() - time_start) < time_to_sleep)
		usleep(MAX_USLEEP);
}

t_ts	current_ms_timestamp(void)
{
	struct timeval		tv;
	unsigned long long	seconds;
	unsigned long long	microseconds;

	if (gettimeofday(&tv, NULL))
		return (0);
	seconds = (unsigned long long)(tv.tv_sec);
	microseconds = (unsigned long long)(tv.tv_usec);
	return ((seconds * 1000) + (microseconds / 1000));
}

bool	print_current_action(t_philos *philos)
{
	pthread_mutex_lock(philos->locks.lprint);
	if (has_someone_died(philos) || is_dead(philos))
	{
		pthread_mutex_unlock(philos->locks.lprint);
		return (false);
	}
	printf("%s%llu%s\t", LGREY, current_ms_timestamp() - philos->start_ts, NC);
	if (philos->action == TAKING_LEFT_FORK)
		printf("%d is taking left fork\n", philos->id);
	else if (philos->action == TAKING_RIGHT_FORK)
		printf("%d is taking right fork\n", philos->id);
	else if (philos->action == EATING)
		printf("%d is eating\n", philos->id);
	else if (philos->action == THINKING)
		printf("%d is thinking\n", philos->id);
	else if (philos->action == SLEEPING)
		printf("%d is sleeping\n", philos->id);
	else if (philos->action == ESCAPING)
		printf("%d is trying to escape! Police is notified\n", philos->id);
	pthread_mutex_unlock(philos->locks.lprint);
	return (true);
}

bool	philo_next_action(t_philos *philos)
{
	bool	ret;

	if (philos->action == EATING)
		ret = philo_sleep(philos);
	else if (philos->action == THINKING)
		ret = philo_eat(philos);
	else if (philos->action == SLEEPING)
		ret = philo_think(philos);
	else if (philos->action == ESCAPING)
		ret = philo_sleep(philos);
	else
		ret = philo_escape(philos);
	return (ret);
}
