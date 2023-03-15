/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:27:20 by hateisse          #+#    #+#             */
/*   Updated: 2022/10/30 05:27:21 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	lit_len;

	if (!*little)
		return ((char *)big);
	i = 0;
	lit_len = ft_strlen(little);
	while (i < len && big[i])
	{
		if (big[i] == *little)
			if (lit_len <= len - i && ft_strncmp(&big[i], little, lit_len) == 0)
				return ((char *)(big + i));
		i++;
	}
	return (0);
}
