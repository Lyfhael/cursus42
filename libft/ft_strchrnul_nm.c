/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrnul_nm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:26:19 by hateisse          #+#    #+#             */
/*   Updated: 2023/05/10 14:38:01 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrnul_nm(const char *s, char *set)
{
	int	i;

	i = -1;
	while (s[++i])
		if (!ft_strchr(set, s[i]))
			break ;
	return ((char *)&s[i]);
}
