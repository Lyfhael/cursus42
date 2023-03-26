/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:31:29 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/26 16:49:46 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
#include <sys/wait.h>

typedef struct s_fork
{
	int		ifd;
	int		ofd;
	char	*command;
	char	*cmd_path;
	char	**envp;
	char	**argv;
}	t_fork;

#endif
