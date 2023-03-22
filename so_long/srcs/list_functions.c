/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:33:40 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/22 23:45:11 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lsaddback(t_img_ptr **lst, t_img_ptr *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->prev = ft_lslast(*lst);
		ft_lslast(*lst)->next = new;
	}
}

void	*ft_lschr_img_ptr(t_img_ptr *img_ptrs, int y, int x, int type)
{
	t_img_ptr	*lst;

	lst = img_ptrs;
	while (lst)
	{
		if (lst->x == x && lst->y == y && lst->type == type)
		{
			return (lst->img_ptr);
		}
		lst = lst->next;
	}
	return ((void *)0);
}

void	ft_lsremoveif(t_img_ptr **img_ptrs, void *mlx_ptr, int y, int x)
{
	t_img_ptr	*lst;

	lst = *img_ptrs;
	while (lst)
	{
		if (lst->x == x && lst->y == y)
		{
			if (lst->prev)
				lst->prev->next = lst->next;
			else
				*img_ptrs = lst->next;
			if (lst->next)
				lst->next->prev = lst->prev;
			if (lst->img_ptr)
				mlx_destroy_image(mlx_ptr, lst->img_ptr);
			free(lst);
			return ;
		}
		lst = lst->next;
	}
}

t_img_ptr	*ft_lsnew(int type, int y, int x, void *img_ptr)
{
	t_img_ptr	*new;

	new = malloc(sizeof(*new) * 1);
	if (!new)
		return (NULL);
	new->type = type;
	new->x = x;
	new->y = y;
	new->img_ptr = img_ptr;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_img_ptr	*ft_lslast(t_img_ptr *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
			lst = lst->next;
	return (lst);
}

