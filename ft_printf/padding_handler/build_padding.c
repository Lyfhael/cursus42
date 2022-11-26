/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:32:35 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/15 18:32:46 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*_pf_build_padding(t_flag *flag, char *s, char **padding)
{
	size_t	len;
	int		extra;

	extra = 0;
	if (flag->zero_value != -1 && flag->identifier == 'c')
		extra -= 1;
	len = (size_t)flag->v_width - ft_strlen(s) + extra;
	*padding = ft_calloc(len + 1, sizeof(*padding));
	if (!*padding)
		return (NULL);
	if (flag->precision != -1 || flag->minus != -1)
		ft_memset(*padding, ' ', len);
	else if (ft_strchr("cs", flag->identifier))
		ft_memset(*padding, ' ', len);
	else if (flag->zero != -1)
		ft_memset(*padding, '0', len);
	else
		ft_memset(*padding, ' ', len);
	return (*padding);
}
