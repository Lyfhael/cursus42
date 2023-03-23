/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:13:49 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/23 16:13:58 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_n_display_image(t_window *win_info, int y, int x, int type)
{
	void	*img_ptr;
	void	*win_ptr;
	char	*filename;
	int		w;
	int		h;

	filename = ft_type_to_path(type, win_info);
	img_ptr = mlx_xpm_file_to_image(win_info->mlx_ptr, filename, &w, &h);
	if (!img_ptr)
		ft_close_window(win_info);
	win_ptr = win_info->win_ptr;
	mlx_put_image_to_window(win_info->mlx_ptr, win_ptr, img_ptr, x, y);
	ft_lsaddback(&win_info->img_ptrs, ft_lsnew(type, y, x, img_ptr));
}

void	ft_display_images(t_window *win_info)
{
	int		y;
	int		x;
	char	**map;

	map = win_info->map_info->map;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			ft_load_n_display_image(win_info, y * 64, x * 64, map[y][x]);
		}
	}
}
