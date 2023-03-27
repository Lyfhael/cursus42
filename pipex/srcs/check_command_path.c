/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:58:31 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/27 18:01:00 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_fetch_paths(char **envp)
{
	char	*paths_list;
	char	**paths;
	int		i;

	i = -1;
	paths = NULL;
	paths_list = NULL;
	if (!envp)
		return (NULL);
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

int	ft_check_if_path_and_is_valid(char *str)
{
	if (ft_strchr(str, '/') != 0)
	{
		if (access(str, F_OK) == -1)
			return (1);
	}
	return (0);
}
