/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag_characters.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:15:05 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/15 21:11:43 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	_pf_parse_flag_characters(const char **to_parse_addr, t_flag *flag)
{
	const char	*to_parse;

	to_parse = *to_parse_addr;
	while (ft_strchr("-+#0 ", *to_parse))
	{
		if (*to_parse == '-')
			flag->minus = 1;
		else if (*to_parse == '+')
			flag->plus = 1;
		else if (*to_parse == '#')
			flag->hashtag = 1;
		else if (*to_parse == '0')
			flag->zero = 1;
		else if (*to_parse == ' ')
			flag->blank = 1;
		to_parse++;
	}
	*to_parse_addr = to_parse;
}
