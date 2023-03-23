/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:32:59 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/23 16:56:24 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int errno, t_map *map_info)
{
	if (errno == 0)
		ft_putstr_fd("Error\nNo map file specified.\n", 2);
	else if (errno == 1)
		ft_putstr_fd("Error\nWrong map extension. It must be a .ber file\n", 2);
	else if (errno == 2)
		ft_putstr_fd("Error\nFailed to open map file.\n", 2);
	else if (errno == 3)
		ft_putstr_fd("Error\nFailed to allocate memory for map_info.\n", 2);
	else if (errno == 4)
		ft_putstr_fd("Error\nCouldn't read the map file until its end.\n", 2);
	else if (errno == 5)
		ft_putstr_fd("Error\nEmpty line detected in map file.\n", 2);
	else if (errno == 6)
		ft_putstr_fd("Error\nMap is not a rectangle.\n", 2);
	else if (errno == 7)
		ft_putstr_fd("Error\nMap is not closed.\n", 2);
	else if (errno == 8)
		ft_putstr_fd("Error\nMap's exit cannot be reached.\n", 2);
	else if (errno == 9)
		ft_putstr_fd("Error\nSome collectibles cannot be reached.\n", 2);
	if (map_info)
		ft_free_map_info(map_info);
	exit(1);
}

void	ft_error_2(int errno, t_map *map_info)
{
	if (errno == 10)
		ft_putstr_fd("Error\nIllegal character in map.\n", 2);
	if (map_info)
		ft_free_map_info(map_info);
	exit(1);
}

void	ft_error_map_info(int errno, t_map *map_info)
{
	if (errno == 0)
		ft_putstr_fd("Error\nMap contains more than 1 exit.\n", 2);
	if (errno == 1)
		ft_putstr_fd("Error\nMap doesn't contain an exit.\n", 2);
	if (errno == 2)
		ft_putstr_fd("Error\nMap contains more than 1 player.\n", 2);
	if (errno == 3)
		ft_putstr_fd("Error\nMap doesn't contain a player.\n", 2);
	if (errno == 4)
		ft_putstr_fd("Error\nMap must contain at least 1 collectible.\n", 2);
	if (map_info)
		ft_free_map_info(map_info);
	exit(1);
}

void	ft_error_mlx(int errno, t_map *map_info)
{
	if (errno == 0)
		ft_putstr_fd("Error\nCould'nt create a new window.\n", 2);
	if (map_info)
		ft_free_map_info(map_info);
	exit(1);
}
