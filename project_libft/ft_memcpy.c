/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:36:09 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/08 13:12:47 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_addr;

	dest_addr = dest;
	if (!dest && dest == src)
		return (NULL);
	while (n-- > 0)
		*(dest_addr++) = *((char *)src++);
	return (dest);
}
