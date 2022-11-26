/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:25:14 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/26 19:51:41 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*_pf_convert_argument(t_flag *flag, va_list ap, char **s)
{
	char	*res;

	res = NULL;
	if (ft_strchr("di", flag->identifier))
		res = _pf_convert_int(flag, va_arg(ap, int));
	else if (ft_strchr("xX", flag->identifier))
		res = _pf_convert_hex(flag, va_arg(ap, unsigned int));
	else if (flag->identifier == 'o')
		res = _pf_convert_octal(flag, va_arg(ap, unsigned int));
	else if (flag->identifier == 'u')
		res = _pf_convert_unsigned_int(flag, va_arg(ap, unsigned int));
	else if (flag->identifier == 'c')
		res = _pf_convert_char(flag, va_arg(ap, int));
	else if (flag->identifier == 's')
		res = _pf_convert_string(va_arg(ap, char *));
	else if (flag->identifier == 'p')
		res = _pf_convert_addr(flag, va_arg(ap, unsigned long));
	else if (flag->identifier == '%')
		res = _pf_convert_perc();
	*s = res;
	return (res);
}

const char	*_pf_convert_main(const char *format, va_list ap, size_t *total)
{
	t_flag	*flag;
	char	*cvarg;

	flag = _pf_parse_flag_directives(format, ALLOC_MODE);
	if (!flag)
		return (NULL);
	cvarg = NULL;
	if (!_pf_convert_argument(flag, ap, &cvarg)
		|| !_pf_add_precision(flag, &cvarg)
		|| !_pf_add_hex_prefix(flag, &cvarg)
		|| !_pf_add_minus_sign_back(flag, &cvarg)
		|| !_pf_add_flag_characters_options(flag, &cvarg)
		|| !_pf_add_padding(flag, &cvarg))
	{
		_pf_free_flag_structure(&flag);
		if (cvarg)
			free(cvarg);
		return (NULL);
	}
	return (_pf_post_conversion_job(flag, cvarg, total));
}
