/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:34:42 by maykman           #+#    #+#             */
/*   Updated: 2022/05/23 23:04:48 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# define MAX_PLAYER_FRAME	16

/*
** Enumerations
*/

typedef enum e_assets_sheets
{
	MAX_ASSETS_SHEET_ID
}	t_assets_sheets;

typedef enum e_tiles
{
	grass,
	grass_grassy,
	grass_flower_red,
	grass_flower_white,
	tree_1,
	tree_2,
	dirt_up_left,
	dirt_up,
	dirt_up_right,
	road_up_left,
	road_up,
	road_up_right,
	tree_3,
	tree_4,
	dirt_left,
	dirt,
	dirt_right,
	road_left,
	road,
	road_right,
	tree_5,
	tree_6,
	dirt_down_right,
	dirt_down,
	dirt_down_left,
	road_down_left,
	road_down,
	road_down_right,
	tree_7,
	tree_8,
	MAX_TILE_ID
}	t_tiles;

/*
** Utils structures
*/

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct	s_area
{
	t_point	p1;
	t_point	p2;
}	t_area;

/*
** Main structures
*/

typedef struct	s_mlx_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_mlx_img;

typedef struct	s_img
{
	void	*img;
	t_point	size;
}	t_img;

typedef struct	s_assets
{
	t_img	assets_sheets[MAX_ASSETS_SHEET_ID];
	t_img	tiles[MAX_TILE_ID];
	t_img	player[MAX_PLAYER_FRAME];
}	t_assets;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_assets	assets;
}	t_data;

#endif