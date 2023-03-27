/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:01:16 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/27 18:01:25 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	load_output(char *filename)
{
	int	fd;

	if (is_directory(filename))
	{
		ft_putstr_fd("Error: is a directory\n", 2);
		return (-1);
	}
	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 00644);
	if (fd == -1)
		perror("output open");
	return (fd);
}


int	load_input(char *filename)
{
	int	fd;

	if (is_directory(filename))
	{
		ft_putstr_fd("Error: is a directory\n", 2);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		perror("input open");
	return (fd);
}
