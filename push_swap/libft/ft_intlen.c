/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:24:30 by hateisse          #+#    #+#             */
/*   Updated: 2022/10/30 05:24:31 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

size_t	ft_intlen(int n)
{
	size_t	len;

	len = 0;
	if (n == INT_MIN)
		return (11);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n / 10 > 0)
	{
		n /= 10;
		len++;
	}
	return (len + 1);
}
