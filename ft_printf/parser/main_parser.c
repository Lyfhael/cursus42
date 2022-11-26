/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:12:11 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/15 20:49:28 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	*_pf_parse_flag_directives(const char *to_parse, char mode)
{
	t_flag	*flag;

	flag = _pf_init_flag_structure();
	if (!flag)
		return (NULL);
	if (_pf_parse_leading_symbol(&to_parse))
	{
		_pf_free_flag_structure(&flag);
		return (NULL);
	}
	if (*to_parse != '%')
	{
		_pf_parse_flag_characters(&to_parse, flag);
		_pf_parse_width_specs(&to_parse, flag);
		_pf_parse_precision_specs(&to_parse, flag);
	}
	if (_pf_parse_type_specifier(&to_parse, flag))
	{
		_pf_free_flag_structure(&flag);
		return (NULL);
	}
	flag->flag_end_index = to_parse + 1;
	if (mode == NO_ALLOC_MODE)
		free(flag);
	return (flag);
}
