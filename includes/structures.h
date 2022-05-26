/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:34:42 by maykman           #+#    #+#             */
/*   Updated: 2022/05/25 00:09:23 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "so_long.h"

// Single dimension tab is way easier on malloc
// But can used as a two-dimensional tab
typedef int	*t_tab;

/*
** Enumerations
*/

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
	MAX_TILE_ID
}	t_tiles;

typedef enum e_key_list
{
	key_up,
	key_down,
	key_left,
	key_right,
	key_esc,
	MAX_KEY
}	t_key_list;

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
}	t_assets;

typedef struct s_player
{
	t_point	pos;
	int		rot;
	int		frame;
}	t_player;

typedef struct s_game
{
	t_player	player;
}	t_game;

typedef struct s_map
{
	t_tab	map;
	t_point	size;
}	t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			key[MAX_KEY];
	t_game		game;
	t_assets	assets;
	t_map		map;
}	t_data;

#endif