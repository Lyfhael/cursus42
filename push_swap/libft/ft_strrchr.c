/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:27:25 by hateisse          #+#    #+#             */
/*   Updated: 2022/10/30 05:33:25 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*found;
	int		i;

	i = -1;
	found = 0;
	while (s[++i])
		if ((unsigned char)s[i] == (unsigned char)c)
			found = (char *)&s[i];
	if (!s[i] && !c)
		found = (char *)&s[i];
	return (found);
}
