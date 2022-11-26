/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_characters_options_convert.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:44:05 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/15 19:44:26 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*_pf_add_hashtag_option(t_flag *flag, char **s)
{
	void	*addr;

	if (flag->hashtag == -1 || flag->zero_value == 1)
		return (*s);
	addr = *s;
	if (flag->identifier == 'x')
		*s = ft_strjoin("0x", *s);
	else if (flag->identifier == 'X')
		*s = ft_strjoin("0X", *s);
	else if (flag->identifier == 'o')
		*s = ft_strjoin("0", *s);
	else
		return (*s);
	free(addr);
	return (*s);
}

char	*_pf_add_minus_sign_back(t_flag *flag, char **s)
{
	void	*addr;

	addr = *s;
	if (ft_strchr("di", flag->identifier) && flag->is_positive == 0)
		*s = ft_strjoin("-", *s);
	if (addr != *s)
		free(addr);
	return (*s);
}

char	*_pf_add_plus_option(t_flag *flag, char **s)
{
	void	*addr;

	if (flag->plus == -1 || (flag->zero_value == 1 && !**s))
		return (*s);
	addr = *s;
	if ((ft_strchr("id", flag->identifier) && flag->is_positive)
		|| flag->identifier == 'p')
	{
		if (flag->is_positive)
			*s = ft_strjoin("+", *s);
		else
			*s = ft_strjoin("-", *s);
		free(addr);
	}
	return (*s);
}

char	*_pf_add_blank_option(t_flag *flag, char **s)
{
	void	*addr;

	if (flag->blank == -1 || flag->plus != -1 || flag->is_positive == 0
		|| (flag->zero_value == 1 && !**s))
		return (*s);
	addr = *s;
	if (ft_strchr("idp", flag->identifier))
	{
		*s = ft_strjoin(" ", *s);
		free(addr);
	}
	return (*s);
}

char	*_pf_add_flag_characters_options(t_flag *flag, char **s)
{
	if (!_pf_add_plus_option(flag, s)
		|| !_pf_add_hashtag_option(flag, s)
		|| !_pf_add_blank_option(flag, s))
		return (NULL);
	return (*s);
}
