/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:35:28 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/18 19:34:36 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lsfree(t_stack *lst, t_stack *lst2)
{
	t_stack	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	while (lst2)
	{
		tmp = lst2;
		lst2 = lst2->next;
		free(tmp);
	}
}

t_stack	*ft_lschr(t_stack *lst, int to_find)
{
	while (lst)
	{
		if (lst->value == to_find)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_stack	*ft_lslast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_lsbeforelast(t_stack *lst)
{
	if (!lst && !lst->next)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_lsnew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(*new) * 1);
	if (!new)
		return (NULL);
	new->value = content;
	new->next = NULL;
	return (new);
}
