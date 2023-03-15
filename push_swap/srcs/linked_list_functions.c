/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:35:28 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/15 17:00:45 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_lschr(t_stack *lst, int to_find)
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

t_stack *ft_lsnew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(*new) * 1);
	if (!new)
		return (NULL);
	new->value = content;
	new->next = NULL;
	return (new);
}

void	ft_lsaddback(t_stack **lst, t_stack *new)
{
	if (!new)
		ft_error(0, lst);
	if (!*lst)
		*lst = new;
	else
		ft_lslast(*lst)->next = new;
}
