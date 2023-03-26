/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:14:26 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/26 19:47:26 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_window	*ft_init_and_create_window(t_map *map_info)
{
	t_window	*win_info;
	int			x;
	int			y;

	x = map_info->x_len;
	y = map_info->y_len;
	win_info = ft_calloc(1, sizeof(t_window));
	win_info->map_info = map_info;
	win_info->mlx_ptr = mlx_init();
	ft_check_map_size(win_info);
	win_info->win_ptr = mlx_new_window(win_info->mlx_ptr, x * 64, y * 64,
			GAME_TITLE);
	win_info->img_ptrs = NULL;
	if (!win_info->win_ptr)
	{
		ft_error_mlx(0, win_info->map_info);
		ft_free_win_info(win_info);
		free(win_info);
		exit(1);
	}
	return (win_info);
}
