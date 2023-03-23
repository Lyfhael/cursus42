/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:29:05 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/23 20:05:08 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int erno)
{
	if (erno == 0)
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
	if (erno == 1)
		perror("Error");
	exit(1);
}

int	open_output(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC);
	if (fd == -1)
		ft_error(1);
}

int	main(int argc, char **argv)
{
	t_params fds;

	if (argc != 5)
		ft_error(0);
	return (0);
}
