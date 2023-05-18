/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:26:19 by hateisse          #+#    #+#             */
/*   Updated: 2023/05/03 20:48:01 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_set(const char *s, char *set)
{
	int	i;

	i = -1;
	while (s[++i])
		if (ft_strchr(set, s[i]))
			return ((char *)&s[i]);
	if (!s[i] && !*set)
		return ((char *)&s[i]);
	return (0);
}
