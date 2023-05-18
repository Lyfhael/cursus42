/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 01:36:49 by hateisse          #+#    #+#             */
/*   Updated: 2023/05/18 05:07:24 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCTS_H

# define PHILO_STRUCTS_H

# include <pthread.h>
# include <stdbool.h>

enum e_philo_errors
{
	ERMAXVAL,
	ERNONDIGIT,
	ERNEGVAL,
	EREMPTYVAL,
	ERZEROVAL,
	ERMUTINIT,
	ERLSNEW,
	ERMALLOC
};

enum e_philo_states
{
	STARTING,
	ALIVE,
	DEAD,
	EXITED
};

enum e_philo_actions
{
	TAKING_FORK,
	EATING,
	SLEEPING,
	THINKING,
	ESCAPING
};

typedef unsigned char		t_pstate;
typedef unsigned char		t_fork;
typedef unsigned char		t_action;
typedef unsigned long long	t_ts;
typedef unsigned long long	t_microseconds;
typedef short				t_id;

typedef struct s_philo_params
{
	int					nb_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_meals;
}	t_philo_params;

typedef struct s_locks
{
	pthread_mutex_t	*lprint;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*lstate;
	pthread_mutex_t	*lexit;
	pthread_mutex_t	*lmeal_ts;
}	t_locks;

typedef struct s_philos
{
	t_id				id;
	t_ts				last_meal_ts;
	t_ts				start_ts;
	short				nb_meals;
	t_action			action;
	t_pstate			state;
	t_philo_params		philo_params;
	t_locks				locks;
	bool				thread_has_exit;
	struct s_philos		*right;
	struct s_philos		*left;
}	t_philos;

#endif
