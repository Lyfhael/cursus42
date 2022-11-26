/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flag_structure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:36:36 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/15 18:37:03 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	*_pf_init_flag_structure(void)
{
	t_flag	*flag;

	flag = malloc(sizeof(*flag) * (1));
	if (!flag)
		return (NULL);
	flag->precision = -1;
	flag->width = -1;
	flag->v_precision = 0;
	flag->v_width = 0;
	flag->blank = -1;
	flag->minus = -1;
	flag->plus = -1;
	flag->zero = -1;
	flag->hashtag = -1;
	flag->identifier = -1;
	flag->is_positive = 1;
	flag->zero_value = -1;
	flag->flag_end_index = 0;
	return (flag);
}
