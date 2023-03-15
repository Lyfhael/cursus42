/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:25:16 by hateisse          #+#    #+#             */
/*   Updated: 2022/10/30 05:35:16 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*addr;
	int					i;

	addr = s;
	i = -1;
	while (n-- > 0)
		if ((unsigned char)addr[++i] == (unsigned char)c)
			return ((void *)&addr[i]);
	return (0);
}
