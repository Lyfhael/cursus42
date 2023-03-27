/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fork_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:56:32 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/27 18:37:35 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_fork	*ft_init_fork(int iofds[2], int tube[2], char *args, char **envp)
{
	t_fork	*params;
	char	**command_n_args;

	params = ft_calloc(1, sizeof(t_fork));
	if (!params)
		return (ft_error(6), NULL);
	command_n_args = ft_split(args, ' ');
	if (!command_n_args)
		return (free(params), ft_error(6), NULL);
	params->argv = command_n_args;
	set_iofds(params->tube, tube[0], tube[1]);
	params->ifd = iofds[0];
	params->ofd = iofds[1];
	params->envp = envp;
	params->command = ft_strdup(command_n_args[0]);
	if (ft_check_if_path_and_is_valid(command_n_args[0]) || !params->command)
		return (ft_free_fork_struct(params), ft_error(1), NULL);
	if (ft_strchr(command_n_args[0], '/'))
		params->cmd_path = ft_strdup(command_n_args[0]);
	else
		params->cmd_path = ft_seek_command_path(command_n_args[0], envp);
	if (!params->cmd_path)
		return (ft_free_fork_struct(params), ft_error(7), NULL);
	return (params);
}

void	ft_free_fork_struct(t_fork *lst)
{
	if (!lst)
		return ;
	if (lst->argv)
		ft_strsfree(lst->argv);
	if (lst->command)
		free(lst->command);
	if (lst->cmd_path)
		free(lst->cmd_path);
	if (lst->ofd != -1)
		close(lst->ofd);
	free(lst);
}
