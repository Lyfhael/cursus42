/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultobase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:25:12 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/06 07:47:50 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static void	ulong_to_str_base(char *s, unsigned long n, short base)
{
	if (n != 0)
	{
		ulong_to_str_base(s - 1, n / base, base);
		*s = "0123456789abcdefghijklmnopqrstuvwxyz"[n % base];
	}
}

static size_t	ft_llen_base(unsigned long n, short base)
{
	size_t	len;

	len = 0;
	while (n / base != 0)
	{
		n /= base;
		len++;
	}
	return (len + 1);
}

char	*ft_ultobase(unsigned long n, short base)
{
	size_t	len;
	char	*res;

	if (!n || base < 2 || base > 36)
		return (ft_strdup("0"));
	len = ft_llen_base(n, base);
	res = ft_calloc(len + 1, sizeof(*res));
	if (!res)
		return (NULL);
	ulong_to_str_base(&res[len - 1], n, base);
	return (res);
}
