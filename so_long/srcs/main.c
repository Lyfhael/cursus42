/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:29:21 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/21 18:38:23 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map_info;

	if (argc != 2)
		ft_error(0, NULL);
	if (!ft_str_endswith(argv[1], ".ber"))
		ft_error(1, NULL);
	map_info = ft_init_map_info();
	ft_get_map_file(argv[1], map_info);
	ft_free_map_info(map_info);
	return (0);
}
