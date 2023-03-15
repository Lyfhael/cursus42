/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:14:48 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/06 12:04:56 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcasestr(const char *haystack, const char *needle)
{
	size_t	nlen;

	if (!*needle)
		return ((char *)haystack);
	nlen = ft_strlen(needle);
	while (*haystack)
	{
		if (*haystack == *needle && !ft_strcasencmp(haystack, needle, nlen))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
