/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:40:16 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/04 16:41:34 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ctos(unsigned char c)
{
	char	*res;

	res = ft_calloc(sizeof(c), 2);
	if (!res)
		return (NULL);
	*res = c;
	return (res);
}
