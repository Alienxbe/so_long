/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:34:42 by maykman           #+#    #+#             */
/*   Updated: 2022/05/23 20:56:07 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

/*
** Enumerations
*/

typedef enum e_assets
{
	grass,
	grassy_grass,
	flower1_grass,
	flower2_grass,
	pkmn_grass,
	sign,
	red,
	p1_spritesheet,
	p1_front,
	mid_grass,
	assets_count
}	t_assets;

/*
** Utils structures
*/

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

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

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	assets[assets_count];
}	t_data;

#endif