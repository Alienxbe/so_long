/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 23:54:20 by mykman            #+#    #+#             */
/*   Updated: 2022/05/26 23:12:41 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>

# include <time.h>
# include "mlx.h"
# include "libft.h"
# include "structures.h"

# define WIN_WIDTH				750
# define WIN_HEIGHT				500
# define WIN_NAME				"so_long"

# define FPS_MAX				60
# define FRAME_PER_ANIMATION	7

# define XPM_TILESET			"assets/xpm/tileset_sheet.xpm"
# define XPM_PLAYER				"assets/xpm/sprite_sheets/beladonis_sprite.xpm"
# define TILE_SIZE				32

# ifndef OS
#  define OS	"None"
# endif

/*
** Functions
*/

// Game
void			exit_game(t_data *d);

// Assets
void			init_assets(t_data *d);

// Window
void			init_win(t_data *d);

// Map
void			set_tile(t_data d, t_asset img, int id, t_point pos);
void			parse_map(t_data *d, const char *filename);

// Errors
void			ft_error(const char *error_msg);

/*
** Utils functions
*/

// MLX custom functions
void			ft_pixel_put(t_mlx_img *img, int x, int y, unsigned int color);
unsigned int	ft_get_pixel_color(t_mlx_img *img, int x, int y);
t_mlx_img		ft_img_to_mlx_img(void	*img);
t_img			ft_xpm_file_to_img(void *mlx_ptr, char *filename);
t_img			ft_new_subimage(void *mlx_ptr, t_img img, t_area area);

// Points
t_point			ft_new_point(int x, int y);
t_point			ft_pos_cmp(t_point p1, t_point p2);
void			ft_print_point(t_point p);

// Areas
t_area			ft_new_area(int x1, int y1, int x2, int y2);
t_area			ft_point_to_area(t_point p1, t_point p2);

#endif
