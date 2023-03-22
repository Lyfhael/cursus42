/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:29:21 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/22 23:52:08 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

t_window	*ft_init_and_create_window(int y, int x)
{
	t_window	*win_info;

	win_info = ft_calloc(1, sizeof(t_window));
	win_info->mlx_ptr = mlx_init();
	win_info->win_ptr = mlx_new_window(win_info->mlx_ptr, x * 64, y * 64, GAME_TITLE);
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

int	ft_on_window_close(t_window *win_info)
{
	ft_free_map_info(win_info->map_info);
	mlx_destroy_display(win_info->mlx_ptr);
	free(win_info);
	printf("exit program");
	exit(0);
}

void	ft_close_window(t_window *win_info)
{
	mlx_destroy_window(win_info->mlx_ptr, win_info->win_ptr);
	ft_on_window_close(win_info);
}

int	target_is_object(char **map, int *p_pos, int object, int move_direction)
{
	if (move_direction == A)
	{
		if (map[p_pos[0]][p_pos[1] - 1] == object)
			return (1);
	}
	if (move_direction == S)
	{
		if (map[p_pos[0] + 1][p_pos[1]] == object)
			return (1);
	}
	if (move_direction == D)
	{
		if (map[p_pos[0]][p_pos[1] + 1] == object)
			return (1);
	}
	if (move_direction == W)
	{
		if (map[p_pos[0] - 1][p_pos[1]] == object)
			return (1);
	}
	return (0);
}

int	get_new_pos(int vector, int move_direction, int *p_pos)
{
	if (move_direction == A && vector == 'x')
		return (p_pos[1] - 1);
	if (move_direction == A && vector == 'y')
		return (p_pos[0]);
	if (move_direction == S && vector == 'x')
		return (p_pos[1]);
	if (move_direction == S && vector == 'y')
		return (p_pos[0] + 1);
	if (move_direction == D && vector == 'x')
		return (p_pos[1] + 1);
	if (move_direction == D && vector == 'y')
		return (p_pos[0]);
	if (move_direction == W && vector == 'x')
		return (p_pos[1]);
	if (move_direction == W && vector == 'y')
		return (p_pos[0] - 1);
	return (0);
}

void	edit_p_pos_and_map(int *npos, int *p_pos, char **map, int newobj)
{
	map[p_pos[0]][p_pos[1]] = newobj;
	map[npos[0]][npos[1]] = 'P';
	p_pos[0] = npos[0];
	p_pos[1] = npos[1];
}

void	move_to_collectible(char **map, int *p_pos, int move, t_window *win_info)
{
	int		npos[2];
	//void	*img_ptr;
	int		y;
	int		x;

	y = p_pos[0];
	x = p_pos[1];
	npos[0] = get_new_pos('y', move, p_pos);
	npos[1] = get_new_pos('x', move, p_pos);
	//img_ptr = ft_lschr_img_ptr(win_info->img_ptrs, y, x, 'P');
	//mlx_destroy_image(win_info->mlx_ptr, img_ptr);
	//img_ptr = ft_lschr_img_ptr(win_info->img_ptrs, npos[0], npos[1], 'V');
	//mlx_destroy_image(win_info->mlx_ptr, img_ptr);
	ft_load_and_display_image(win_info, y * 64, x * 64, '0');
	ft_load_and_display_image(win_info, npos[0] * 64, npos[1] * 64, 'P');
	edit_p_pos_and_map(npos, p_pos, map, 'V');
}

void	move_to_ground(char **map, int *p_pos, int move, t_window *win_info)
{
	int		npos[2];
	//void	*img_ptr;
	int		y;
	int		x;

	y = p_pos[0];
	x = p_pos[1];
	npos[0] = get_new_pos('y', move, p_pos);
	npos[1] = get_new_pos('x', move, p_pos);
	//img_ptr = ft_lschr_img_ptr(win_info->img_ptrs, y, x, 'P');
	//mlx_destroy_image(win_info->mlx_ptr, img_ptr);
	//img_ptr = ft_lschr_img_ptr(win_info->img_ptrs, npos[0], npos[1], '0');
	//mlx_destroy_image(win_info->mlx_ptr, img_ptr);
	ft_load_and_display_image(win_info, y * 64, x * 64, '0');
	ft_load_and_display_image(win_info, npos[0] * 64, npos[1] * 64, 'P');
	edit_p_pos_and_map(npos, p_pos, map, '0');
}

int	handle_key_pressed(int key, t_window *win_info)
{
	char	**map;

	map = win_info->map_info->map;
	if (key == ESCAPE)
		ft_close_window(win_info);
	if (key == A || key == S || key == D || key == W)
	{
		if (target_is_object(map, win_info->map_info->p_pos, '0', key))
			move_to_ground(map, win_info->map_info->p_pos, key, win_info);
		else if (target_is_object(map, win_info->map_info->p_pos, 'V', key))
			move_to_collectible(map, win_info->map_info->p_pos, key, win_info);
	}
	printf("Key pressed: %d (%p)\n", key, win_info->map_info);
	return (0);
}

void	ft_create_hooks(t_window *win_info)
{
	mlx_hook(win_info->win_ptr, 17, 0, &ft_on_window_close, win_info);
	mlx_key_hook(win_info->win_ptr, &handle_key_pressed, win_info);
}

char	*ft_type_to_path(int type, t_window *win_info)
{
	if (type == '0')
		return (GROUND_SPRITE);
	if (type == '1')
		return (WALL_SPRITE);
	if (type == 'P')
		return (PLAYER_S0_SPRITE);
	if (type == 'V')
		return (COLLECTIBLE_SPRITE);
	if (type == 'E')
		return (EXIT_SPRITE);
	else
	{
		ft_putstr_fd("Error\nNo sprites found for this element\n", 2);
		ft_close_window(win_info);
		return ("");
	}
}

void	ft_load_and_display_image(t_window *win_info, int y, int x, int type)
{
	void	*img_ptr;
	char	*filename;
	int		w;
	int		h;

	filename = ft_type_to_path(type, win_info);
	printf("%s %p %p\n", filename, win_info->mlx_ptr, win_info->win_ptr);
	img_ptr = mlx_xpm_file_to_image(win_info->mlx_ptr, filename, &w, &h);
	if (!img_ptr)
		ft_close_window(win_info);
	mlx_put_image_to_window(win_info->mlx_ptr, win_info->win_ptr, img_ptr, x, y);
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
			ft_load_and_display_image(win_info, y * 64, x * 64, map[y][x]);
		}
	}
}

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
	win_info = ft_init_and_create_window(map_info->y_len, map_info->x_len);
	win_info->map_info = map_info;
	ft_display_images(win_info);
	ft_create_hooks(win_info);
	mlx_loop(win_info->mlx_ptr);
	return (0);
}
