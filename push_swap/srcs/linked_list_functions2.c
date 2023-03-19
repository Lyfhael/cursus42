/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_functions2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:37:13 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/18 18:34:31 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lslen(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	ft_lsaddfront(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lsaddback(t_stack **lst, t_stack *new)
{
	if (!new)
		ft_error(0, lst, NULL);
	if (!*lst)
		*lst = new;
	else
		ft_lslast(*lst)->next = new;
}
