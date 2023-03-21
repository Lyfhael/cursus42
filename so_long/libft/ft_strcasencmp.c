/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasencmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:27:13 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/08 07:38:15 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcasencmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned char		*ucs1;
	unsigned char		*ucs2;

	ucs1 = (unsigned char *)s1;
	ucs2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && ucs1[i] && ft_tolower(ucs1[i]) == ft_tolower(ucs2[i]))
		i++;
	return (ft_tolower(ucs1[i]) - ft_tolower(ucs2[i]));
}
