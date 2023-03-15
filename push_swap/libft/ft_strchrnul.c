/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrnul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:26:28 by hateisse          #+#    #+#             */
/*   Updated: 2022/10/30 05:33:51 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchrnul(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
	return ((char *)&s[i]);
}
