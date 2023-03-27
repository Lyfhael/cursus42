/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:02:05 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/27 18:02:17 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error(int erno)
{
	if (erno == 0)
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
	if (erno == 1)
		perror("Error");
	if (erno == 2)
		perror("Pipe:");
	if (erno == 3)
		perror("Fork:");
	if (erno == 4)
		perror("Dup2");
	if (erno == 5)
		perror("Execve");
	if (erno == 6)
		return (perror("Malloc"), exit(1), 0);
	if (erno == 7)
		ft_putstr_fd("Error: command not found.\n", 2);
	return (0);
}
