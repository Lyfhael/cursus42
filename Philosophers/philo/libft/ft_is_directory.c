/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_directory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 23:18:05 by hateisse          #+#    #+#             */
/*   Updated: 2023/05/07 12:55:53 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

int	is_directory(char *file_name)
{
	struct stat	sb;

	if (stat(file_name, &sb) == -1)
		return (-1);
	return (S_ISDIR(sb.st_mode));
}
