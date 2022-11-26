/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:22:30 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/15 18:22:39 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*_pf_convert_addr(t_flag *flag, unsigned long n)
{
	char	*s;

	if (n == 0)
		flag->zero_value = 1;
	if (!n)
		return (ft_strdup("(nil)"));
	s = ft_ultobase(n, 16);
	return (s);
}
