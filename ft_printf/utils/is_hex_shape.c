/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hex_shape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:35:41 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/15 21:11:16 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	_pf_is_hex_shape(t_flag *flag)
{
	if (flag->zero_value != -1)
		return (0);
	if (flag->identifier == 'p')
		return (1);
	if (flag->hashtag != -1 && ft_strchr("xX", flag->identifier))
		return (1);
	return (0);
}
