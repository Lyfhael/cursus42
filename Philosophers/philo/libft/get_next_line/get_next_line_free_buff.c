/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_free_buff.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:41:00 by hateisse          #+#    #+#             */
/*   Updated: 2023/05/07 12:56:09 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <stdarg.h>

void	gnl_force_finish(int nb, ...)
{
	char	*line;
	int		fd;
	va_list	ap;

	va_start(ap, nb);
	line = NULL;
	while (nb--)
	{
		fd = va_arg(ap, int);
		get_next_line(fd, &line);
		while (line)
		{
			free(line);
			get_next_line(fd, &line);
		}
		close(fd);
	}
	va_end(ap);
}
