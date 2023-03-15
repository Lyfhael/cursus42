/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:27:30 by hateisse          #+#    #+#             */
/*   Updated: 2022/10/30 05:27:31 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_strsfree(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}
