/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_to_sprite_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:13:14 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/23 16:13:29 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
