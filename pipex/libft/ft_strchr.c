/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:26:19 by hateisse          #+#    #+#             */
/*   Updated: 2022/10/30 05:34:05 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
	if (!s[i] && !c)
		return ((char *)&s[i]);
	return (0);
}
