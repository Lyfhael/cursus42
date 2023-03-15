/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:27:04 by hateisse          #+#    #+#             */
/*   Updated: 2022/10/30 05:27:05 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*res;

	len = ft_strlen(s);
	res = ft_calloc(len + 1, sizeof(*res));
	if (!res)
		return (NULL);
	while (len-- > 0)
		res[len] = f(len, s[len]);
	return (res);
}
