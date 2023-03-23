/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_and_get_map_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:15:19 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/23 16:15:27 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
