/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:29:05 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/26 20:08:49 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int erno)
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
		perror("Malloc");
	if (erno == 7)
		ft_putstr_fd("Error: Couldn't fetch", 2);
	exit(1);
}

char	*ft_get_env_element(char **envp, char *element)
{
	int		i;
	char	*path;

	i = -1;
	path = "";
	while (envp[++i])
		if (!ft_strncmp(envp[i], element, 5))
			path = envp[i];
	return (path);
}

int	load_output(char *filename)
{
	int	fd;

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 00644);
	if (fd == -1)
		perror("output open");
	return (fd);
}

int	load_input(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		perror("input open");
	return (fd);
}

int	ft_fork_it(t_fork *params)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_error(4);
	else if (pid == 0)
	{
		if (params->ifd != -1 && dup2(params->ifd, STDIN_FILENO) == -1)
			ft_error(4);
		if (params->ofd != -1 && dup2(params->ofd, STDOUT_FILENO) == -1)
			ft_error(4);
		if (execve(params->cmd_path, params->argv, params->envp) == -1)
			ft_error(5);
	}
	else
	{
		close(params->ifd);
		wait(NULL);
	}
	return (0);
}

char	**ft_fetch_paths(char **envp)
{
	char	*paths_list;
	char	**paths;
	int		i;

	i = -1;
	paths = NULL;
	paths_list = NULL;
	while (envp[++i])
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			paths_list = envp[i];
	paths = ft_split(paths_list, ':');
	return (paths);
}

char	*ft_seek_command_path(char *command, char **envp)
{
	char	**paths;
	char	*test_path;
	int		i;

	paths = ft_fetch_paths(envp);
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		test_path = ft_strsjoin(3, paths[i], "/", command);
		if (!test_path)
			return (ft_error(6), NULL);
		if (access(test_path, F_OK) == 0)
		{
			ft_strsfree(paths);
			return (test_path);
		}
		free(test_path);
	}
	ft_strsfree(paths);
	return (NULL);
}

t_fork	*ft_init_fork(int input_fd, int output_fd, char *args, char **envp)
{
	t_fork	*params;
	char	**command_n_args;

	params = ft_calloc(1, sizeof(t_fork));
	if (!params)
		return (ft_error(6), NULL);
	command_n_args = ft_split(args, ' ');
	if (!command_n_args)
		return (free(params), ft_error(6), NULL);
	params->ifd = input_fd;
	params->ofd = output_fd;
	params->envp = envp;
	params->command = command_n_args[0];
	params->cmd_path = ft_seek_command_path(command_n_args[0], envp);
	if (!params->cmd_path)
		return (ft_strsfree(command_n_args), free(params), ft_error(7), NULL);
	params->argv = command_n_args;
	return (params);
}

void	ft_print_buffer(int fd)
{
	int		ret;
	char	*result;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &result);
		printf("[%d] %s\n", ret, result);
	}
}

int	pipex(int input_fd, int output_fd, char *cmd_n_params, char **envp)
{
	t_fork *params;

	params = ft_init_fork(input_fd, output_fd, cmd_n_params, envp);
	if (!params)
		return (1);
	ft_fork_it(params);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		tube[2];

	if (argc != 5)
		ft_error(0);
	if (pipe(tube) == -1)
		ft_error(2);
	pipex(load_input(argv[1]), tube[1], argv[2], envp);
	close(tube[1]);
	pipex(tube[0], load_output(argv[4]), argv[3], envp);
	ft_print_buffer(tube[0]);
	close(tube[0]);
	return (0);
}
