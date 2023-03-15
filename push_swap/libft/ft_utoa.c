/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:25:12 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/04 16:30:29 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	copy_uint_to_str(char *s, unsigned int n)
{
	if (n > 9)
		copy_uint_to_str(s - 1, n / 10);
	*s = (n % 10) + 48;
}

char	*ft_utoa(unsigned int n)
{
	size_t	len;
	char	*res;

	len = ft_uintlen(n);
	res = ft_calloc(len + 1, sizeof(*res));
	if (!res)
		return (NULL);
	copy_uint_to_str(&res[len - 1], n);
	return (res);
}
