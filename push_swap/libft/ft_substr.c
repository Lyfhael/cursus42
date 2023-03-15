/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:27:56 by hateisse          #+#    #+#             */
/*   Updated: 2022/10/30 05:27:56 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*res;

	slen = ft_strlen(s);
	if (slen < start)
		return (ft_calloc(1, sizeof(*res)));
	slen = ft_strlen(&s[start]);
	if (len < slen)
		slen = len;
	res = ft_calloc(slen + 1, sizeof(*res));
	if (!res)
		return (NULL);
	ft_memcpy(res, &s[start], slen);
	return (res);
}
