/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:34:03 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/26 19:53:39 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_ground_chars_to_zero(char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'F')
				map[y][x] = '0';
		}
	}
}

void	ft_check_if_valid_path_exist(t_map *map_info)
{
	ft_flood_fill(map_info->p_pos[0], map_info->p_pos[1], map_info);
	ft_set_ground_chars_to_zero(map_info->map);
	if (map_info->exit_reachable == 0)
		ft_error(8, map_info);
	if (map_info->can_be_collected != map_info->collectibles)
		ft_error(9, map_info);
}

void	ft_check_map_size(t_window *win_info)
{
	int	max_x;
	int	max_y;

	max_x = 1920;
	max_y = 1080;
	mlx_get_screen_size(win_info->mlx_ptr, &max_x, &max_y);
	if (win_info->map_info->x_len * 64 > max_x
		|| win_info->map_info->y_len * 64 > max_y)
	{
		ft_putstr_fd("Error\nMap too big compared to your screen size.\n", 2);
		ft_free_map_info(win_info->map_info);
		mlx_destroy_display(win_info->mlx_ptr);
		if (win_info->mlx_ptr)
			free(win_info->mlx_ptr);
		free(win_info);
		exit(1);
	}
}

void	ft_check_map_info_arguments(t_map *map_info)
{
	if (map_info->exits > 1)
		ft_error_map_info(0, map_info);
	else if (map_info->exits == 0)
		ft_error_map_info(1, map_info);
	if (map_info->players > 1)
		ft_error_map_info(2, map_info);
	else if (map_info->players == 0)
		ft_error_map_info(3, map_info);
	if (map_info->collectibles == 0)
		ft_error_map_info(4, map_info);
}
