/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env_element.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:04:08 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/27 18:04:16 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_env_element(char **envp, char *element)
{
	int		i;
	char	*path;

	i = -1;
	path = "";
	while (envp[++i])
		if (!ft_strncmp(envp[i], element, 5))
			path = envp[i];
	return (path);
}
