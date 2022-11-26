/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_flag_structure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:37:14 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/15 18:37:20 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	*_pf_free_flag_structure(t_flag **flag)
{
	if (flag && *flag)
	{
		free(*flag);
		*flag = NULL;
	}
	return (*flag);
}
