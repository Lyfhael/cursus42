/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 01:54:21 by hateisse          #+#    #+#             */
/*   Updated: 2023/05/28 20:40:49 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_usage(void)
{
	printf("Usage: ./philo number_of_philosophers time_to_die time_to_eat \
	\btime_to_sleep [number_of_times_each_philosopher_must_eat]\n");
}

void	print_error(int errno, char *context)
{
	if (errno == ERMAXVAL)
		printf("Error: Argument `%s` exceeds INT_MAX\n", context);
	else if (errno == ERNONDIGIT)
		printf("Error: Argument `%s` contains non-digit characters\n", context);
	else if (errno == ERNEGVAL)
		printf("Error: Argument `%s` should not be negative\n", context);
	else if (errno == EREMPTYVAL)
		printf("Error: Argument should not be empty\n");
	else if (errno == ERZEROVAL)
		printf("Error: Argument should be superior to 0\n");
	else if (errno == ERMALLOC)
		printf("Error: malloc() failed\n");
	else if (errno == ERMUTINIT)
		printf("Error: pthread_mutex_init() failed\n");
	else if (errno == ERLSNEW)
		printf("Error: philos_ls_new() failed\n");
}
