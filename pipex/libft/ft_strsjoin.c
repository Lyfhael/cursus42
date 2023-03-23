/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:26:47 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/06 09:25:40 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>

char	*ft_strsjoin(unsigned int count, ...)
{
	char	*res;
	void	*tmp;
	va_list	ap;

	va_start(ap, count);
	res = NULL;
	while (count--)
	{
		tmp = res;
		res = ft_strjoin(res, va_arg(ap, char *));
		free(tmp);
		if (!res)
			break ;
	}
	va_end(ap);
	return (res);
}
