/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision_specification.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:16:47 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/15 21:01:43 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	_pf_parse_precision_specs(const char **to_parse_addr, t_flag *flag)
{
	if (**to_parse_addr == '.')
	{
		*to_parse_addr += 1;
		flag->precision = 1;
		flag->v_precision = ft_strtol(*to_parse_addr, to_parse_addr, 10);
		if (flag->v_precision < 0 || flag->v_precision >= INT_MAX - 32)
			flag->v_precision = -1;
	}
}
