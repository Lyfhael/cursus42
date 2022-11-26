/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:34:34 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/15 18:34:53 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*_pf_build_precision(t_flag *flag, char *s)
{
	char	*res;
	size_t	len;

	if ((size_t)flag->v_precision <= ft_strlen(s))
		return (ft_strdup(""));
	len = (size_t)flag->v_precision - ft_strlen(s);
	res = ft_calloc(len + 1, sizeof(*res));
	if (!res)
		return (NULL);
	return (ft_memset(res, '0', len));
}
