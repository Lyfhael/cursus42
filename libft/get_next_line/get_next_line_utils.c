/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:39:31 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/08 12:30:47 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (*src && i < n)
		dest[i++] = *(src++);
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

void	gnl_lstfree(t_gnl **buflist, int fd)
{
	t_gnl	*current;
	t_gnl	*next;

	current = *buflist;
	while (current)
	{
		next = current->next;
		if (current->fd == fd)
		{
			if (current->buf)
				free(current->buf);
			current->buf = NULL;
			if (current->localbuf)
				free(current->localbuf);
			if (current->prev)
				current->prev->next = current->next;
			if (next)
				next->prev = current->prev;
			if (current == *buflist)
				*buflist = next;
			free(current);
		}
		current = next;
	}
}

t_gnl	*gnl_lstnew(int fd)
{
	t_gnl	*new;

	new = malloc(sizeof(*new) * 1);
	if (!new)
		return (NULL);
	new->fd = fd;
	new->buf = malloc(1);
	new->localbuf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new->localbuf || !new->buf)
	{
		gnl_lstfree(&new, fd);
		return (NULL);
	}
	*(new->buf) = '\0';
	(new->localbuf)[BUFFER_SIZE] = '\0';
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_gnl	*gnl_lstadd_back(t_gnl **lst, t_gnl *new)
{
	t_gnl	*tmp;

	if (!new)
		return (NULL);
	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		if (!tmp)
			return (NULL);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		tmp->next->prev = tmp;
	}
	return (*lst);
}

t_gnl	*gnl_lstsrch(t_gnl *lst, int fd)
{
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
