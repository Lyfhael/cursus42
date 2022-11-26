/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_d_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:20:27 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/15 18:20:41 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*_pf_convert_int(t_flag *flag, int n)
{
	char			*res;

	if (n == 0)
		flag->zero_value = 1;
	if (n < 0)
	{
		flag->is_positive = 0;
		res = ft_utoa(-n);
	}
	else
		res = ft_itoa(n);
	return (res);
}
