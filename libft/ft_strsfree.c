/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:27:30 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/21 14:05:20 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_strsfree(char **strs)
{
	size_t	i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}
