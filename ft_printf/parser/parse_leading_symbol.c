/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_leading_symbol.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:18:12 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/15 18:18:33 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	_pf_parse_leading_symbol(const char **to_parse)
{
	if (**to_parse == '%')
	{
		*to_parse += 1;
		return (0);
	}
	return (1);
}
