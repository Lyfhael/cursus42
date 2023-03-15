/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:25:12 by hateisse          #+#    #+#             */
/*   Updated: 2022/10/30 05:25:13 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	copy_int_to_str(char *s, int n)
{
	if (n > 9)
		copy_int_to_str(s - 1, n / 10);
	*s = (n % 10) + 48;
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n);
	res = ft_calloc(len + 1, sizeof(*res));
	if (!res)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		*res = '-';
	}
	copy_int_to_str(&res[len - 1], n);
	return (res);
}
