/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:09:59 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/23 16:16:02 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	move_to_exit(t_window *win_info)
{
	float	y;
	float	x;
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = win_info->mlx_ptr;
	win_ptr = win_info->win_ptr;
	y = ((win_info->map_info->y_len / 2) * 64);
	x = ((win_info->map_info->x_len / 2) * 64);
	update_and_print_moves(win_info);
	destroy_all_images(&win_info->img_ptrs, win_info->mlx_ptr);
	mlx_clear_window(win_info->mlx_ptr, win_info->win_ptr);
	mlx_string_put(mlx_ptr, win_ptr, (int)x, (int)y, GREEN, "YOU WIN!");
	win_info->map_info->game_end = 1;
}

void	move_to_ground(char **map, int *p_pos, int move, t_window *win_info)
{
	int			npos[2];
	int			y;
	int			x;

	y = p_pos[0];
	x = p_pos[1];
	npos[0] = get_new_pos('y', move, p_pos);
	npos[1] = get_new_pos('x', move, p_pos);
	ft_lsremoveif(win_info, 'P', y * 64, x * 64);
	ft_lsremoveif(win_info, '0', npos[0] * 64, npos[1] * 64);
	ft_load_n_display_image(win_info, y * 64, x * 64, '0');
	ft_load_n_display_image(win_info, npos[0] * 64, npos[1] * 64, 'P');
	edit_p_pos_and_map(npos, p_pos, map, '0');
	update_and_print_moves(win_info);
}

void	move_to_collectible(char **map, int *p_pos, int move, t_window *w_info)
{
	int			npos[2];
	int			y;
	int			x;

	y = p_pos[0];
	x = p_pos[1];
	npos[0] = get_new_pos('y', move, p_pos);
	npos[1] = get_new_pos('x', move, p_pos);
	ft_lsremoveif(w_info, 'P', y * 64, x * 64);
	ft_lsremoveif(w_info, 'V', npos[0] * 64, npos[1] * 64);
	ft_load_n_display_image(w_info, y * 64, x * 64, '0');
	ft_load_n_display_image(w_info, npos[0] * 64, npos[1] * 64, 'P');
	edit_p_pos_and_map(npos, p_pos, map, '0');
	update_and_print_moves(w_info);
}

void	update_and_print_moves(t_window *win_info)
{
	ft_putstr_fd("Total moves:", 1);
	ft_putnbr_fd(++win_info->map_info->moves, 1);
	ft_putchar_fd('\n', 1);
}
