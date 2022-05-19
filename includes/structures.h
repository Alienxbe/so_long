/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:34:42 by maykman           #+#    #+#             */
/*   Updated: 2022/05/20 00:54:37 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef enum e_assets
{
	grass,
	grassy_grass,
	flower_grass,
	pkmn_grass,
	assets_count
}	t_assets;

typedef struct	s_game
{
	int posx;
	int posy;
}	t_game;

typedef struct	s_img
{
	void	*img;
	int		height;
	int		width;
}	t_img;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	assets[assets_count];
	t_game	game;
}	t_data;

#endif