/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_hex_prefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:28:17 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/15 18:28:32 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*_pf_add_hex_prefix(t_flag *flag, char **s)
{
	void	*addr;

	addr = *s;
	if (flag->identifier == 'p' && ft_strcmp(*s, "(nil)"))
		*s = ft_strjoin("0x", *s);
	if (addr != *s)
		free(addr);
	return (*s);
}
