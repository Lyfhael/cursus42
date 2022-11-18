/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 07:45:37 by hateisse          #+#    #+#             */
/*   Updated: 2022/11/15 21:14:04 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 4092

typedef struct s_gnl
{
	int				fd;
	char			*buf;
	char			*localbuf;
	struct s_gnl	*next;
	struct s_gnl	*prev;
}	t_gnl;

char	*ft_strncpy(char *dest, const char *src, size_t n);

t_gnl	*gnl_lstnew(int fd);
t_gnl	*gnl_lstadd_back(t_gnl **lst, t_gnl *new);
void	gnl_lstfree(t_gnl **buflist, int fd);
t_gnl	*gnl_lstsrch(t_gnl *lst, int fd);

short	gnl_check_buf(char **line, char *localbuf, t_gnl *buf_fd);
short	gnl_precheck(char **line, t_gnl **buflist, int fd);
short	gnl_readfile(char **line, t_gnl *buf_fd, int fd);
char	*gnl_expand(char **dest, char *src, char *to_add);
char	*get_next_line(int fd);

#endif
