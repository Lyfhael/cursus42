/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:39:50 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/21 16:24:44 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_array_str(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_putstr_fd(array[i], 1);
		ft_putstr_fd("\n", 1);
		array++;
	}
}
