/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:47:47 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/08 12:30:10 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

short	gnl_check_buf(char **line, char *localbuf, t_gnl *buf_fd)
{
	int		pos_nl;
	int		i;
	char	**buf;

	while (*localbuf && *localbuf != '\n')
		localbuf++;
	if (*localbuf != '\n')
		return (0);
	buf = &buf_fd->buf;
	pos_nl = -1;
	while (buf[0][++pos_nl])
		if (buf[0][pos_nl] == '\n')
			break ;
	if (buf[0][pos_nl] != '\n')
		return (0);
	*line = malloc(sizeof(**line) * (pos_nl + 1 + 1));
	if (!*line)
		return (-1);
	line[0][pos_nl + 1] = '\0';
	ft_strncpy(*line, *buf, pos_nl + 1);
	i = 0;
	while (buf[0][i])
		i++;
	ft_strncpy(&(buf[0][0]), &(buf[0][pos_nl + 1]), i + 1);
	return (1);
}

short	gnl_precheck(char **line, t_gnl **buflist, int fd)
{
	short	check_ret;
	t_gnl	*buf_fd;

	if (fd < 0)
		return (-1);
	if (!gnl_lstsrch(*buflist, fd))
	{
		if (!gnl_lstadd_back(buflist, gnl_lstnew(fd)))
			return (-2);
	}
	else
	{
		buf_fd = gnl_lstsrch(*buflist, fd);
		check_ret = gnl_check_buf(line, buf_fd->localbuf, buf_fd);
		if (check_ret < 0)
			return (-3);
	}
	return (0);
}

char	*gnl_expand(char **dest, char *src, char *to_add)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (src[i])
		i++;
	j = 0;
	while (to_add[j])
		j++;
	res = malloc(sizeof(*res) * (i + j + 1));
	if (!res)
		return (NULL);
	res[i + j] = '\0';
	i = -1;
	while (src[++i])
		res[i] = src[i];
	while (*to_add)
		res[i++] = *(to_add++);
	free(src);
	*dest = res;
	return (res);
}

short	gnl_readfile(char **line, t_gnl *buf_fd, int fd)
{
	short	read_ret;
	short	check_ret;

	read_ret = read(fd, buf_fd->localbuf, BUFFER_SIZE);
	while (read_ret > 0)
	{
		buf_fd->localbuf[read_ret] = '\0';
		if (!gnl_expand(&buf_fd->buf, buf_fd->buf, buf_fd->localbuf))
			return (-2);
		check_ret = gnl_check_buf(line, buf_fd->localbuf, buf_fd);
		if (check_ret == -1)
			return (-3);
		else if (check_ret == 1)
			return (1);
		read_ret = read(fd, buf_fd->localbuf, BUFFER_SIZE);
	}
	if (read_ret == 0 && *buf_fd->buf)
	{
		gnl_expand(line, buf_fd->buf, "");
		buf_fd->buf = NULL;
	}
	return (read_ret);
}

char	*get_next_line(int fd)
{
	static t_gnl	*buflist;
	short			read_ret;
	char			*line;

	line = NULL;
	if (gnl_precheck(&line, &buflist, fd) < 0)
	{
		gnl_lstfree(&buflist, fd);
		return (NULL);
	}
	else if (line)
		return (line);
	read_ret = gnl_readfile(&line, gnl_lstsrch(buflist, fd), fd);
	if (read_ret < 1)
	{
		gnl_lstfree(&buflist, fd);
		if (read_ret < 0)
			return (NULL);
	}
	return (line);
}
/*
int	main(void)
{
	int	fd[5];

	fd[0] = open("test", O_RDONLY);
	fd[1] = open("test2", O_RDONLY);

}*/
