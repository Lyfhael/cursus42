/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philos_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 01:30:11 by hateisse          #+#    #+#             */
/*   Updated: 2023/05/16 17:49:25 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philos	*philos_ls_last(t_philos *lst)
{
	while (lst->right)
		lst = lst->right;
	return (lst);
}

t_philos	*philos_ls_new(int id, t_philo_params philo_params)
{
	t_philos			*new;

	new = ft_calloc(1, sizeof(t_philos));
	if (!new)
		return (free(new), NULL);
	new->action = SLEEPING;
	new->philo_params = philo_params;
	new->id = id;
	new->state = STARTING;
	new->thread_has_exit = false;
	if (init_philos_mutex(new) == false)
		return (free(new), NULL);
	return (new);
}

void	philos_ls_addback(t_philos **head, t_philos *new)
{
	t_philos	*lst;

	if (!*head)
	{
		*head = new;
		return ;
	}
	lst = *head;
	while (lst->right)
		lst = lst->right;
	lst->right = new;
	new->left = lst;
}

void	philos_ls_free(t_philos **arg)
{
	t_philos	*ptr;
	int			i;

	i = (*arg)->philo_params.nb_philos;
	while (i--)
	{
		ptr = (*arg)->right;
		if (i == 0)
			free_mutex((*arg)->locks.lprint);
		free_mutex((*arg)->locks.lfork);
		free_mutex((*arg)->locks.lstate);
		free_mutex((*arg)->locks.lexit);
		free_mutex((*arg)->locks.lmeal_ts);
		free(*arg);
		*arg = ptr;
	}
	*arg = NULL;
}
