/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:33:22 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/22 23:39:30 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# define GAME_TITLE "so_long"

# define ESCAPE 65307
# define W 119
# define D 100
# define S 115
# define A 97

# define GROUND_SPRITE "./sprites/tile00.xpm"
# define WALL_SPRITE "./sprites/tile01.xpm"
# define COLLECTIBLE_SPRITE "./sprites/ball.xpm"
# define EXIT_SPRITE "./sprites/ladder.xpm"
# define PLAYER_S0_SPRITE "./sprites/player_S00.xpm"

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_window
{
	void				*mlx_ptr;
	void				*win_ptr;
	struct s_map		*map_info;
	struct s_img_ptr	*img_ptrs;
}	t_window;

typedef struct s_img_ptr
{
	void				*img_ptr;
	int					y;
	int					x;
	int					type;
	struct s_img_ptr	*next;
	struct s_img_ptr	*prev;
}	t_img_ptr;

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

void		ft_load_and_display_image(t_window *win_info, int y, int x, int type);

void		ft_lsaddback(t_img_ptr **lst, t_img_ptr *new);
void		ft_lsremoveif(t_img_ptr **img_ptrs, void *mlx_ptr, int y, int x);
t_img_ptr	*ft_lsnew(int type, int y, int x, void *img_ptr);
t_img_ptr	*ft_lslast(t_img_ptr *lst);
void		*ft_lschr_img_ptr(t_img_ptr *img_ptrs, int y, int x, int type);

int			ft_on_window_close(t_window *win_info);

t_window	*ft_init_and_create_window(int y, int x);

void		ft_trim_nl(char *line);

void		ft_free_map_info(t_map *map_info);
void		ft_free_win_info(t_window *win_info);

void		ft_error(int errno, t_map *map_info);
void		ft_error_map_info(int errno, t_map *map_info);
void		ft_error_mlx(int errno, t_map *map_info);

t_map		*ft_init_map_info(void);

void		ft_get_map_file(char *filename, t_map *map_info);
void		ft_parse_line(char *line, int y, int fst_or_lst, t_map *map_info);
void		ft_check_map_info_arguments(t_map *map_info);
void		ft_check_if_valid_path_exist(t_map *map_info);
void		ft_parse_map(t_map *map_info);

void		ft_flood_fill_right_bot(int y, int x, t_map *map_info);
void		ft_flood_fill_left_bot(int y, int x, t_map *map_info);
void		ft_flood_fill_right_top(int y, int x, t_map *map_info);
void		ft_flood_fill_left_top(int y, int x, t_map *map_info);
#endif