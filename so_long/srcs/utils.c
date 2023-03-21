/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:30:13 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/21 18:35:01 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_trim_nl(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len && line[len - 1] == '\n')
		line[len - 1] = 0;
}

void	ft_free_map_info(t_map *map_info)
{
	ft_strsfree(map_info->map);
	free(map_info);
}

t_map	*ft_init_map_info(void)
{
	t_map	*map_info;

	map_info = ft_calloc(1, sizeof(t_map));
	if (!map_info)
		ft_error(3, NULL);
	map_info->map = NULL;
	map_info->p_pos[0] = 0;
	map_info->p_pos[1] = 0;
	map_info->collectibles = 0;
	map_info->exits = 0;
	map_info->players = 0;
	map_info->y_len = 0;
	map_info->x_len = 0;
	map_info->can_be_collected = 0;
	map_info->exit_reachable = 0;
	return (map_info);
}