/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:20:49 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/15 18:21:05 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*_pf_convert_unsigned_int(t_flag *flag, unsigned int n)
{
	if (n == 0)
		flag->zero_value = 1;
	return (ft_utoa(n));
}
