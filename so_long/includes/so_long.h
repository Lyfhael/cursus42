/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:33:22 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/21 18:53:04 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_map
{
	char	**map;
	int		y_len;
	int		x_len;
	int		players;
	int		p_pos[2];
	int		collectibles;
	int		can_be_collected;
	int		exit_reachable;
	int		exits;
}	t_map;

void	ft_trim_nl(char *line);

void	ft_free_map_info(t_map *map_info);
void	ft_error(int errno, t_map *map_info);
void	ft_error_map_info(int errno, t_map *map_info);

t_map	*ft_init_map_info(void);

void	ft_get_map_file(char *filename, t_map *map_info);
void	ft_parse_line(char *line, int y, int first_or_last, t_map *map_info);
void	ft_check_map_info_arguments(t_map *map_info);
void	ft_check_if_valid_path_exist(t_map *map_info);
void	ft_parse_map(t_map *map_info);

void	ft_flood_fill_right_bot(int y, int x, t_map *map_info);
void	ft_flood_fill_left_bot(int y, int x, t_map *map_info);
void	ft_flood_fill_right_top(int y, int x, t_map *map_info);
void	ft_flood_fill_left_top(int y, int x, t_map *map_info);
#endif