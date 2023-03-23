/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:35:21 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/23 19:26:54 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_parse_line(char *line, int y, int fst_or_lst, t_map *map_info)
{
	int	x;

	x = -1;
	while (line[++x])
	{
		if ((fst_or_lst || x == 0 || !line[x + 1]) && line[x] != '1')
			ft_error(7, map_info);
		if (!ft_strchr("01PEC", line[x]))
			ft_error_2(10, map_info);
		if (line[x] == 'P')
		{
			map_info->players++;
			map_info->p_pos[0] = y;
			map_info->p_pos[1] = x;
		}
		else if (line[x] == 'E')
			map_info->exits++;
		else if (line[x] == 'C')
			map_info->collectibles++;
	}
	if (x == 0)
		ft_error(5, map_info);
}

void	ft_parse_map(t_map *map_info)
{
	int	y;
	int	first_or_last;

	y = -1;
	if (!map_info->map)
		ft_error(6, map_info);
	while (map_info->map[++y])
	{
		if (y == 0 || !map_info->map[y + 1])
			first_or_last = 1;
		else
			first_or_last = 0;
		map_info->y_len++;
		ft_parse_line(map_info->map[y], y, first_or_last, map_info);
		if (y > 0 && (int)ft_strlen(map_info->map[y]) != map_info->x_len)
			ft_error(6, map_info);
		map_info->x_len = ft_strlen(map_info->map[y]);
	}
	ft_check_map_info_arguments(map_info);
	ft_check_if_valid_path_exist(map_info);
}

void	ft_get_map_file(char *filename, t_map *map_info)
{
	int		fd;
	int		gnl_ret;
	char	*tmp;

	tmp = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(2, map_info);
	while (1)
	{
		gnl_ret = get_next_line(fd, &tmp);
		if (gnl_ret == 0 && tmp == 0)
			break ;
		ft_trim_nl(tmp);
		if (gnl_ret == -1)
			ft_error(4, map_info);
		map_info->map = ft_strs_expand(map_info->map, tmp);
		tmp = NULL;
	}
	close(fd);
	ft_parse_map(map_info);
}
