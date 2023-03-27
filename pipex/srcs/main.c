/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:29:05 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/27 18:36:26 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_fork_it(t_fork *params)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_error(4);
	else if (pid == 0)
	{
		if (params->tube[0] != params->ifd)
			close(params->tube[0]);
		if (params->tube[1] != params->ofd)
			close(params->tube[1]);
		if (params->ifd != -1 && dup2(params->ifd, STDIN_FILENO) == -1)
			ft_error(4);
		close(params->ifd);
		if (params->ofd != -1 && dup2(params->ofd, STDOUT_FILENO) == -1)
			ft_error(4);
		close(params->ofd);
		if (execve(params->cmd_path, params->argv, params->envp) == -1)
			ft_error(5);
	}
	else
		close(params->ifd);
	wait(NULL);
	return (0);
}

int	pipex(int iofds[2], int tube[2], char *cmd_n_params, char **envp)
{
	t_fork	*params;

	if (iofds[0] == -1)
		return (-1);
	if (iofds[1] == -1)
		return (-1);
	params = ft_init_fork(iofds, tube, cmd_n_params, envp);
	if (!params)
		return (1);
	ft_fork_it(params);
	ft_free_fork_struct(params);
	return (0);
}

void	set_iofds(int iofds[2], int input_fd, int output_fd)
{
	iofds[0] = input_fd;
	iofds[1] = output_fd;
}

int	main(int argc, char **argv, char **envp)
{
	int		tube[2];
	int		iofds[2];

	if (argc != 5)
		return (ft_error(0), 1);
	if (pipe(tube) == -1)
		return (ft_error(2), 1);
	set_iofds(iofds, load_input(argv[1]), tube[1]);
	pipex(iofds, tube, argv[2], envp);
	close(tube[1]);
	set_iofds(iofds, tube[0], load_output(argv[4]));
	pipex(iofds, tube, argv[3], envp);
	close(tube[0]);
	return (0);
}
