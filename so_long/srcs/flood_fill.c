/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:30:00 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/26 19:30:20 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit_else_continue(char c, int y, int x, t_map *map_info)
{
	if (c == 'E')
		map_info->exit_reachable = 1;
	else
		ft_flood_fill(y, x, map_info);
}

void	ft_flood_fill(int y, int x, t_map *map_info)
{
	if (map_info->map[y][x] == 'C')
	{
		map_info->can_be_collected += 1;
		map_info->map[y][x] = 'V';
	}
	if (map_info->map[y][x] == '0')
		map_info->map[y][x] = 'F';
	if (y < map_info->y_len - 1 && !ft_strchr("1PF", map_info->map[y + 1][x]))
		check_exit_else_continue(map_info->map[y + 1][x], y + 1, x, map_info);
	if (y > 0 && !ft_strchr("1FPV", map_info->map[y - 1][x]))
		check_exit_else_continue(map_info->map[y - 1][x], y - 1, x, map_info);
	if (x < map_info->x_len - 1 && !ft_strchr("1PF", map_info->map[y][x + 1]))
		check_exit_else_continue(map_info->map[y][x + 1], y, x + 1, map_info);
	if (x > 0 && !ft_strchr("1FPV", map_info->map[y][x - 1]))
		check_exit_else_continue(map_info->map[y][x - 1], y, x - 1, map_info);
}
