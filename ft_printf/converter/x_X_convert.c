/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_X_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:22:59 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/15 18:23:11 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*_pf_convert_hex(t_flag *flag, unsigned int n)
{
	char	*s;

	if (n == 0)
		flag->zero_value = 1;
	s = ft_ultobase(n, 16);
	if (!s)
		return (NULL);
	if (flag->identifier == 'X')
		ft_strtoupper(s);
	return (s);
}
