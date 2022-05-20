/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 06:11:05 by mykman            #+#    #+#             */
/*   Updated: 2022/05/21 00:51:52 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	new_asset(void *mlx_ptr, char *filename)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx_ptr, filename, &img.width, &img.height);
	return (img);
}

void	init_assets(t_data *d)
{
	t_pos	pos1;
	t_pos	pos2;
	int		sprite;

	sprite = 1 + 0 * 4; // Maths to get sprite (frame + rotation * 4)
	ft_bzero(d->assets, sizeof(t_img) * assets_count);
	d->assets[grass] = new_asset(d->mlx_ptr, XPM_FOLDER"grass.xpm");
	d->assets[grassy_grass] = new_asset(d->mlx_ptr, XPM_FOLDER"grassy_grass.xpm");
	d->assets[flower1_grass] = new_asset(d->mlx_ptr, XPM_FOLDER"flower1_grass.xpm");
	d->assets[flower2_grass] = new_asset(d->mlx_ptr, XPM_FOLDER"flower2_grass.xpm");
	d->assets[pkmn_grass] = new_asset(d->mlx_ptr, XPM_FOLDER"pkmn_grass.xpm");
	d->assets[sign] = new_asset(d->mlx_ptr, XPM_FOLDER"sign.xpm");
	d->assets[red] = new_asset(d->mlx_ptr, XPM_FOLDER"red.xpm");
	// Maths to get sprite position
	pos1 = ft_set_pos(0 + 64 * (sprite % 4), 0 + 64 * (sprite / 4));
	pos2 = ft_set_pos(64 + 64 * (sprite % 4), 64 + 64 * (sprite / 4));
	d->assets[p1_spritesheet] = new_asset(d->mlx_ptr, XPM_FOLDER"sprite_sheets/bw_girl_sprite.xpm");
	d->assets[p1_front] = ft_new_subimage(d->mlx_ptr, d->assets[p1_spritesheet], pos1, pos2);
	pos1 = ft_set_pos(16, 16);
	pos2 = ft_set_pos(32, 32);
	d->assets[mid_grass] = ft_new_subimage(d->mlx_ptr, d->assets[pkmn_grass], pos1, pos2);
}
