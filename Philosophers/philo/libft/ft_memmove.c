/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:25:31 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/08 13:13:30 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_addr;

	if (!dest && dest == src)
		return (NULL);
	dest_addr = dest;
	if (dest <= src)
		while (n-- > 0)
			*(dest_addr++) = *((char *)src++);
	else
		while (n-- > 0)
			*(dest_addr + n) = *((char *)src + n);
	return (dest);
}
