/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:49:32 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/15 20:21:46 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	_pf_print_then_advance(const char *format, size_t *total)
{
	size_t	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%'
			&& _pf_parse_flag_directives(&format[i], NO_ALLOC_MODE))
			break ;
		(*total)++;
		i++;
	}
	ft_putnstr(format, i);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	total;

	va_start(ap, format);
	total = 0;
	while (*format)
	{
		format += _pf_print_then_advance(format, &total);
		if (*format == '%')
		{
			format = _pf_convert_main(format, ap, &total);
			if (!format)
			{
				va_end(ap);
				return (-1);
			}
		}
	}
	va_end(ap);
	return (total);
}
