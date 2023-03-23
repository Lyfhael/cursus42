/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:12:24 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/23 16:12:46 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	all_collected(char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'V')
				return (0);
		}
	}
	return (1);
}

int	handle_key_pressed(int key, t_window *win_info)
{
	char	**map;

	map = win_info->map_info->map;
	if (key == ESCAPE)
		ft_close_window(win_info);
	if ((key == A || key == S || key == D || key == W)
		&& win_info->map_info->game_end == 0)
	{
		if (target_is_object(map, win_info->map_info->p_pos, '0', key))
			move_to_ground(map, win_info->map_info->p_pos, key, win_info);
		else if (target_is_object(map, win_info->map_info->p_pos, 'V', key))
			move_to_collectible(map, win_info->map_info->p_pos, key, win_info);
		else if (target_is_object(map, win_info->map_info->p_pos, 'E', key))
		{
			if (all_collected(map))
				move_to_exit(win_info);
		}
	}
	return (0);
}

void	ft_create_hooks(t_window *win_info)
{
	mlx_hook(win_info->win_ptr, 17, 0, &ft_close_window, win_info);
	mlx_key_hook(win_info->win_ptr, &handle_key_pressed, win_info);
}
