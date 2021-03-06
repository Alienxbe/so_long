/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:34:42 by maykman           #+#    #+#             */
/*   Updated: 2022/06/22 19:43:39 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "common.h"

typedef int		**t_layer;

/*
** Enumerations
*/

typedef enum e_event {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}	t_event;

typedef enum e_tiles_x
{
	player_tile_id,
	coin_tile_id,
	exit_tile_id
}	t_tiles_x;

typedef enum e_tiles
{
	grass,
	grass_grassy,
	grass_flower_red,
	grass_flower_white,
	grass_pkmn,
	sign,
	tree_1,
	tree_2,
	dirt_nw,
	dirt_n,
	dirt_ne,
	road_nw,
	road_n,
	road_ne,
	tree_3,
	tree_4,
	dirt_w,
	dirt,
	dirt_e,
	road_w,
	road,
	road_e,
	tree_5,
	tree_6,
	dirt_sw,
	dirt_s,
	dirt_se,
	road_sw,
	road_s,
	road_se,
	tree_7,
	tree_8,
	dirt_cross_nw,
	dirt_cross_ne,
	ledge_w_0,
	ledge_e_2,
	road_cross_nw,
	road_cross_ne,
	tree_9,
	tree_10,
	dirt_cross_sw,
	dirt_cross_se,
	ledge_w_1,
	ledge_e_1,
	road_cross_sw,
	road_cross_se,
	tree_11,
	tree_12,
	dirt_slope_down_ne,
	dirt_slope_down_nw,
	ledge_w_2,
	ledge_e_0,
	tree_13,
	tree_14,
	tree_15,
	tree_16,
	dirt_slope_down_sw,
	dirt_slope_down_se,
	ledge_s_0,
	ledge_s_1,
	ledge_s_2,
	ledge_n_2,
	ledge_n_1,
	ledge_n_0,
	MAX_TILE_ID,
	NO_TILE = -1
}	t_tiles;

typedef enum e_key_list
{
	key_down,
	key_left,
	key_right,
	key_up,
	key_esc,
	key_tab,
	MAX_KEY
}	t_key_list;

typedef enum e_file_extension
{
	ext_error = -1,
	ext_ber,
	ext_aer
}	t_file_extension;

/*
** Utils structures
*/

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_area
{
	t_point	p1;
	t_point	p2;
}	t_area;

/*
** Main structures
*/

typedef struct s_mlx_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_mlx_img;

typedef struct s_img
{
	void	*img;
	t_point	size;
}	t_img;

typedef struct s_asset
{
	t_img	*list;
	int		count;
}	t_asset;

typedef struct s_assets
{
	t_asset	tiles;
	t_asset	player;
	t_img	menubar;
}	t_assets;

typedef struct s_game
{
	int			key_active[MAX_KEY];
	int			fps;
	int			ismenu;
}	t_game;

typedef struct s_map
{
	int		id_size;
	int		layer_count;
	int		tile_size;
	t_layer	*layers;
	t_layer	col;
	int		*s_id;
	int		*t_id;
	t_point	size;
	t_list	**entities;
}	t_map;

typedef struct s_file
{
	const char			*filename;
	int					fd;
	t_file_extension	ext;
}	t_file;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			key[MAX_KEY];
	t_img		win_img;
	t_point		win_size;
	t_game		game;
	t_list		*entities;
	t_assets	assets;
	t_map		map;
}	t_data;

typedef void	(*t_fparsec)(t_map *, int *, t_point, char *);

#endif