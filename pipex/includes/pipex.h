/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:31:29 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/27 18:33:28 by hateisse         ###   ########.fr       */
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
# include <sys/wait.h>

typedef struct s_fork
{
	int		ifd;
	int		ofd;
	int		tube[2];
	char	*command;
	char	*cmd_path;
	char	**envp;
	char	**argv;
}	t_fork;

void	ft_free_fork_struct(t_fork *lst);
t_fork	*ft_init_fork(int iofds[2], int tube[2], char *args, char **envp);
void	ft_free_fork_struct(t_fork *lst);

int		ft_check_if_path_and_is_valid(char *str);
char	*ft_seek_command_path(char *command, char **envp);
char	**ft_fetch_paths(char **envp);

int		load_output(char *filename);
int		load_input(char *filename);

int		ft_error(int erno);

void	set_iofds(int iofds[2], int input_fd, int output_fd);
int		pipex(int iofds[2], int tube[2], char *cmd_n_params, char **envp);
int		ft_fork_it(t_fork *params);

#endif
