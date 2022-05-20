/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:34:42 by maykman           #+#    #+#             */
/*   Updated: 2022/05/20 23:21:57 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef enum e_assets
{
	grass,
	grassy_grass,
	flower1_grass,
	flower2_grass,
	pkmn_grass,
	sign,
	red,
	red_head,
	assets_count
}	t_assets;

typedef struct	s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct	s_img
{
	void	*img;
	int		height;
	int		width;
}	t_img;

typedef struct	s_mlx_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_mlx_img;

typedef struct	s_game
{
	int posx;
	int posy;
}	t_game;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	assets[assets_count];
	t_game	game;
}	t_data;

#endif