/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:39:03 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/13 16:29:32 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*addr;

	if (!nmemb || !size)
		return (NULL);
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	addr = malloc(size * nmemb);
	if (!addr)
		return (NULL);
	ft_bzero(addr, size * nmemb);
	return (addr);
}
