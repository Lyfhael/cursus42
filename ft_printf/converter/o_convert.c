/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:23:18 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/15 18:24:30 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*_pf_convert_octal(t_flag *flag, unsigned int n)
{
	if (n == 0)
		flag->zero_value = 1;
	return (ft_ultobase(n, 8));
}
