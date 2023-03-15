/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:26:15 by hateisse          #+#    #+#             */
/*   Updated: 2022/10/30 05:26:16 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	dest_len;

	dest_len = ft_strlen(dest);
	while (*src)
		dest[dest_len++] = *(src++);
	dest[dest_len] = '\0';
	return (dest);
}
