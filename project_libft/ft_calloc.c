/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:39:03 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/09 18:42:27 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <errno.h>

static size_t	ft_log_b2(size_t n)
{
	size_t	res;

	res = 0;
	if (n == 1)
		return (0);
	while (n > 0)
	{
			n /= 2;
			res++;
	}
	return (res);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*addr;

	if (!nmemb || !size)
		return (NULL);
	if (ft_log_b2(nmemb) + ft_log_b2(size) > sizeof(size_t) * 8)
	{
		errno = ENOMEM;
		return (NULL);
	}
	addr = malloc(size * nmemb);
	if (!addr)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_bzero(addr, size * nmemb);
	return (addr);
}
