/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:26:37 by hateisse          #+#    #+#             */
/*   Updated: 2022/10/30 05:26:38 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*res;

	res = ft_calloc(ft_strlen(s) + 1, sizeof(*res));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
		res[i++] = *s++;
	return (res);
}
