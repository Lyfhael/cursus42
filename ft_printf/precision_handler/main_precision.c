/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:35:05 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/15 19:38:50 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*_pf_add_precision_build(char **s, char *build)
{
	void	*addr;

	addr = *s;
	*s = ft_strjoin(build, *s);
	free(build);
	if (!*s)
		free(addr);
	return (*s);
}

char	*_pf_add_precision(t_flag *flag, char **s)
{
	void	*addr;
	char	*precision_build;

	addr = *s;
	if (flag->precision == -1)
		return (*s);
	else if (flag->v_precision == 0 && !ft_strcmp(*s, "0")
		&& ft_strchr("xXiodu", flag->identifier))
		*s = ft_strdup("");
	else if (flag->identifier == 's')
		*s = ft_substr(*s, 0, flag->v_precision);
	else if (ft_strchr("xXiodup", flag->identifier))
	{
		precision_build = _pf_build_precision(flag, *s);
		if (!precision_build || !_pf_add_precision_build(s, precision_build))
			return (NULL);
	}
	if (addr != *s)
		free(addr);
	return (*s);
}
