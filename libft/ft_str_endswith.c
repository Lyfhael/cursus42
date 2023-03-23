/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_endswith.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:39:03 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/21 14:01:42 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_endswith(char *str, char *needle)
{
	int	i;
	int	i2;

	i = ft_strlen(str);
	i2 = ft_strlen(needle);
	while (i > 0 && i2 > 0)
	{
		if (needle[--i2] != str[--i])
			return (0);
	}
	if (i2)
		return (0);
	return (1);
}
