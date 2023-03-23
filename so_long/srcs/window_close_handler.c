/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_close_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:11:20 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/23 16:11:44 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_on_window_close(t_window *win_info)
{
	ft_free_map_info(win_info->map_info);
	mlx_destroy_display(win_info->mlx_ptr);
	if (win_info->mlx_ptr)
		free(win_info->mlx_ptr);
	free(win_info);
	exit(0);
}

int	ft_close_window(t_window *win_info)
{
	destroy_all_images(&win_info->img_ptrs, win_info->mlx_ptr);
	mlx_destroy_window(win_info->mlx_ptr, win_info->win_ptr);
	ft_on_window_close(win_info);
	return (0);
}
