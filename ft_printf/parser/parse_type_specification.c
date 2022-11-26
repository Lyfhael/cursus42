/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type_specification.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:17:10 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/15 21:11:08 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	_pf_parse_type_specifier(const char **to_parse, t_flag *flag)
{
	if (ft_strchr("ocspdiuxX%", **to_parse))
		flag->identifier = *(*to_parse++);
	else
		return (1);
	return (0);
}
