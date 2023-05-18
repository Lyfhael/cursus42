/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strschr_here.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:53:42 by hateisse          #+#    #+#             */
/*   Updated: 2023/04/03 19:58:57 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>

int	ft_strschr_here(unsigned int count, char *haystack, ...)
{
	char	*tmp;
	va_list	ap;

	va_start(ap, haystack);
	while (count--)
	{
		tmp = va_arg(ap, char *);
		if (ft_strncmp(tmp, haystack, ft_strlen(tmp)) == 0)
			return (1);
	}
	va_end(ap);
	return (0);
}
