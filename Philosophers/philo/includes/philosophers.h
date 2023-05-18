/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:20:20 by hateisse          #+#    #+#             */
/*   Updated: 2023/05/18 04:59:52 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "philo_structs.h"
# include <stdbool.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include "libft.h"

# define SUCCESS 0
# define FAILURE 1
# define DISABLED -1

# define LGREY "\033[90m"
# define NC "\033[0m"

// philo actions

bool		philo_eat(t_philos *philos);
bool		philo_sleep(t_philos *philos);
bool		philo_think(t_philos *philos);
bool		philo_escape(t_philos *philos);
bool		print_current_action(t_philos *philos);
bool		philo_next_action(t_philos *philos);
void		take_forks(t_philos *philos);
void		lay_forks(t_philos *philos);

// death handling functions

bool		has_someone_died(t_philos *philos);
bool		is_dead(t_philos *philos);
bool		has_exited(t_philos *philos);

// pthread related

bool		launch_philos(t_philos *philos, t_philo_params philo_params);
void		*philo_routine(void *vphilos);

// parsing related

bool		parse_arguments(int ac, char **av, t_philo_params *philo_params);
int			check_argument_validity(char *arg, int argno, int *errno);
long		philo_atol(const char *nptr, long max_value, int *errno);

// error handling functions

void		print_usage(void);
void		print_error(int errno, char *context);

// init_mutex

bool		init_mutex(pthread_mutex_t **mutex);
void		free_mutex(pthread_mutex_t *mutex);
bool		init_philos_mutex(t_philos *new);

// linked list handling functions

t_philos	*philos_ls_last(t_philos *lst);
t_philos	*philos_ls_new(int id, t_philo_params philo_params);
void		philos_ls_addback(t_philos **head, t_philos *new);
void		philos_ls_free(t_philos **arg);
bool		init_philos(t_philos **philos, t_philo_params pparams);

// utils

t_ts		current_ms_timestamp(void);

#endif