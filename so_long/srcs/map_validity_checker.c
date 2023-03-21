/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:34:03 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/21 18:34:33 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_if_valid_path_exist(t_map *map_info)
{
	ft_flood_fill_right_bot(map_info->p_pos[0], map_info->p_pos[1], map_info);
	ft_flood_fill_right_top(map_info->p_pos[0], map_info->p_pos[1], map_info);
	ft_flood_fill_left_top(map_info->p_pos[0], map_info->p_pos[1], map_info);
	ft_flood_fill_left_bot(map_info->p_pos[0], map_info->p_pos[1], map_info);
	if (map_info->exit_reachable == 0)
		ft_error(8, map_info);
	if (map_info->can_be_collected != map_info->collectibles)
		ft_error(9, map_info);
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
