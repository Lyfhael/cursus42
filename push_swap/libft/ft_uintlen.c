/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:24:30 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/04 16:27:31 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

size_t	ft_uintlen(unsigned int n)
{
	size_t	len;

	len = 0;
	while (n / 10 > 0)
	{
		n /= 10;
		len++;
	}
	return (len + 1);
}
