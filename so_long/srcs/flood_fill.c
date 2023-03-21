/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:30:00 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/21 18:30:01 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill_right_bot(int y, int x, t_map *map_info)
{
	if (map_info->map[y][x] == 'C')
	{
		map_info->can_be_collected += 1;
		map_info->map[y][x] = 'V';
	}
	else if (map_info->map[y][x] == 'E')
		map_info->exit_reachable = 1;
	if (y < map_info->y_len - 1)
		ft_flood_fill_right_bot(y + 1, x, map_info);
	if (x < map_info->x_len - 1)
		ft_flood_fill_right_bot(y, x + 1, map_info);
}

void	ft_flood_fill_left_bot(int y, int x, t_map *map_info)
{
	if (map_info->map[y][x] == 'C')
	{
		map_info->can_be_collected += 1;
		map_info->map[y][x] = 'V';
	}
	else if (map_info->map[y][x] == 'E')
		map_info->exit_reachable = 1;
	if (y < map_info->y_len - 1)
		ft_flood_fill_left_bot(y + 1, x, map_info);
	if (x > 0)
		ft_flood_fill_left_bot(y, x - 1, map_info);
}

void	ft_flood_fill_right_top(int y, int x, t_map *map_info)
{
	if (map_info->map[y][x] == 'C')
	{
		map_info->can_be_collected += 1;
		map_info->map[y][x] = 'V';
	}
	else if (map_info->map[y][x] == 'E')
		map_info->exit_reachable = 1;
	if (y > 0)
		ft_flood_fill_right_top(y - 1, x, map_info);
	if (x < map_info->x_len - 1)
		ft_flood_fill_right_top(y, x + 1, map_info);
}

void	ft_flood_fill_left_top(int y, int x, t_map *map_info)
{
	if (map_info->map[y][x] == 'C')
	{
		map_info->can_be_collected += 1;
		map_info->map[y][x] = 'V';
	}
	else if (map_info->map[y][x] == 'E')
		map_info->exit_reachable = 1;
	if (y > 0)
		ft_flood_fill_left_top(y - 1, x, map_info);
	if (x > 0)
		ft_flood_fill_left_top(y, x - 1, map_info);
}
