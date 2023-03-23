/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:36:19 by hateisse          #+#    #+#             */
/*   Updated: 2022/10/30 05:36:20 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1_addr;
	const unsigned char	*s2_addr;

	s1_addr = s1;
	s2_addr = s2;
	i = 0;
	while (i < n)
	{
		if (s1_addr[i] != s2_addr[i])
			return (s1_addr[i] - s2_addr[i]);
		i++;
	}
	return (0);
}
