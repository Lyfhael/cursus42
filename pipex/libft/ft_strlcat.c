/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:26:50 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/08 13:15:38 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;

	if ((!dst || !src) && !size)
		return (0);
	d_len = ft_strlen(dst);
	if (size <= d_len)
		return (size + ft_strlen(src));
	i = 0;
	dst += d_len;
	while (src[i] && d_len + i < size - 1)
		*(dst++) = src[i++];
	*dst = '\0';
	return (d_len + ft_strlen(src));
}
