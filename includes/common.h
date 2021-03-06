/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:49:32 by mykman            #+#    #+#             */
/*   Updated: 2022/06/21 16:22:37 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H


// To remove !!
#include <stdio.h>
#define TEST		ft_printf("TEST ZEBI\n")
#define PRINT_VAR(var, type)	ft_printf("var: `%"type"`\n", var)
#define PRINT_TAB(ptr, size, type)\
{\
		for (int i = 0; i < size; i++)\
			ft_printf("tab %d: %"type"\n", i, ptr[i]);\
}

/*
** Includes
*/

// Used to limit frame rate
# include <time.h>
// Graphical interface
# include "mlx.h"
// Basics functions
# include "libft.h"
// Typedef, structure and unions for this project
# include "structures.h"
// Entity class (Not real a class)
# include "entity.h"

/*
** Define constants
*/

# ifndef OS
#  define OS	"None"
# endif

// FPS
# define SHOW_FPS				1
# define FPS_MAX				60

// Files
# define TILESET_XPM			"assets/xpm/tileset_sheet.xpm"
# define PLAYER_XPM				"assets/xpm/sprite_sheets/lucas_sprite.xpm"

// Map
# define TILES_X_LIST			"PCE"

/*
** Functions
*/

// Game
int			exit_game(t_data *d);

// Assets
void			init_assets(t_data *d);

// Window
void			init_win(t_data *d, char *name);
void			init_keycode(t_data *d);

// Events
int				key_pressed(int key, t_data *d);
int				key_released(int key, t_data *d);
// This function need to be defined outside of common
void			key_actions(t_data *d);

// Rendering
int				update(t_data *d);
int				ajust_frame_rate(int animation_time);
// This function need to be defined outside of common
void			draw(t_data *d);

// Map
void			set_tile(t_data *d, t_asset asset, int id, t_point pos);

// Errors
void			ft_error(const char *error_msg);

/*
** Parsing functions
*/

void			parse(t_data *d, const char *filename);
t_map			read_map(t_file f, t_list **entities);
char			*read_params(t_file f, t_map *map);
char			*read_layers(t_file f, t_map *map, char *line);
t_layer			read_layer(t_file f, t_map *map, char *line, t_fparsec fpc);

// Collision map
void			read_colmap(t_file f, t_map *map, char *line);
t_layer			map_to_col(t_map *map, int (*get_value)(t_map *, t_point));
t_layer			mapid_to_col(t_file f, t_map *map, char *line);

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
