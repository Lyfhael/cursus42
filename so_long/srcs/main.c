/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:29:21 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/26 19:46:25 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map		*map_info;
	t_window	*win_info;

	if (argc != 2)
		ft_error(0, NULL);
	if (!ft_str_endswith(argv[1], ".ber"))
		ft_error(1, NULL);
	map_info = ft_init_map_info();
	ft_get_map_file(argv[1], map_info);
	win_info = ft_init_and_create_window(map_info);
	win_info->map_info = map_info;
	ft_display_images(win_info);
	ft_create_hooks(win_info);
	mlx_loop(win_info->mlx_ptr);
	return (0);
}
