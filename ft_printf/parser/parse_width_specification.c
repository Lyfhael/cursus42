/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width_specification.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:16:07 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/15 20:59:51 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	_pf_parse_width_specs(const char **to_parse_addr, t_flag *flag)
{
	if (ft_isdigit(**to_parse_addr))
	{
		flag->width = 1;
		flag->v_width = ft_strtol(*to_parse_addr, to_parse_addr, 10);
		if (flag->v_width < 0 || flag->v_width >= INT_MAX - 32)
			flag->v_width = -1;
	}
}
