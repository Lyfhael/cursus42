/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_conversion_job.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:26:15 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/15 18:26:36 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*_pf_post_conversion_job(t_flag *flag, char *cvarg, size_t *total)
{
	const char	*flag_end_index;

	flag_end_index = flag->flag_end_index;
	if (flag->identifier == 'c' && flag->zero_value == 1)
		*total += 1;
	if (flag->identifier == 'c' && flag->zero_value == 1 && flag->minus != -1)
		write(1, "\0", 1);
	ft_putstr(cvarg);
	if (flag->identifier == 'c' && flag->zero_value == 1 && flag->minus == -1)
		write(1, "\0", 1);
	*total += ft_strlen(cvarg);
	free(cvarg);
	_pf_free_flag_structure(&flag);
	return (flag_end_index);
}
