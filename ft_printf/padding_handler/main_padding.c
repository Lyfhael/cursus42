/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_padding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:30:48 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/26 19:52:32 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*_pf_add_padding_build_signed_int(char **s, char *padding)
{
	char	*sign_prefix;

	if (*padding == '0')
	{
		sign_prefix = ft_calloc(2, 1);
		if (!sign_prefix)
			return (NULL);
		*sign_prefix = **s;
		*s = ft_strsjoin(3, sign_prefix, padding, *s + 1);
		free(sign_prefix);
	}
	else
		*s = ft_strjoin(padding, *s);
	return (*s);
}

char	*_pf_add_padding_build_hex(t_flag *flag, char **s, char *padding)
{
	size_t	hex_prefix_i;
	char	*hex_prefix;

	hex_prefix_i = 0;
	if (flag->zero != -1 && flag->precision == -1)
	{
		if (flag->identifier == 'X')
			hex_prefix_i = ft_strrchr(*s, 'X') - *s + 1;
		else if (ft_strchr("xp", flag->identifier))
			hex_prefix_i = ft_strrchr(*s, 'x') - *s + 1;
		hex_prefix = ft_substr(*s, 0, hex_prefix_i);
		if (!hex_prefix)
			return (NULL);
		*s = ft_strsjoin(3, hex_prefix, padding, *s + hex_prefix_i);
		free(hex_prefix);
	}
	else
		*s = ft_strjoin(padding, *s);
	return (*s);
}

char	*_pf_add_padding_build(t_flag *flag, char **s, char *padding)
{
	if (flag->minus != -1)
		*s = ft_strjoin(*s, padding);
	else if (_pf_is_hex_shape(flag))
	{
		if (!_pf_add_padding_build_hex(flag, s, padding))
			*s = NULL;
	}
	else if (ft_strchr("di", flag->identifier) && ft_strchr(" +-", **s))
	{
		if (!_pf_add_padding_build_signed_int(s, padding))
			*s = NULL;
	}
	else
		*s = ft_strjoin(padding, *s);
	free(padding);
	return (*s);
}

char	*_pf_add_padding(t_flag *flag, char **s)
{
	char	*padding;
	void	*addr;

	addr = *s;
	if (flag->width == -1 || (size_t)flag->v_width <= ft_strlen(*s))
		return (*s);
	if (!_pf_build_padding(flag, *s, &padding))
		return (NULL);
	_pf_add_padding_build(flag, s, padding);
	if (*s != addr)
		free(addr);
	return (*s);
}
