/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 06:11:05 by mykman            #+#    #+#             */
/*   Updated: 2022/05/24 07:24:03 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	ft_xpm_file_to_img(void *mlx_ptr, char *filename)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx_ptr, filename, &img.size.x,
			&img.size.y);
	return (img);
}

static void	init_asset_sheet(void *mlx_ptr, t_asset *asset, char *filename,
	t_point size)
{
	t_img	img;
	t_point	count;
	int		id;

	img = ft_xpm_file_to_img(mlx_ptr, filename);
	if (!img.img)
		return ;
	count = ft_new_point(img.size.x / size.x, img.size.y / size.y);
	asset->count = count.x * count.y;
	asset->list = ft_calloc(asset->count, sizeof(t_img));
	if (asset->list)
	{
		id = -1;
		while (++id < asset->count)
			asset->list[id] = ft_new_subimage(mlx_ptr, img,
					ft_new_area(
						0 + size.x * (id % count.x),
						0 + size.y * (id / count.x),
						size.x + size.x * (id % count.x),
						size.y + size.y * (id / count.x)
						)
					);
	}
	mlx_destroy_image(mlx_ptr, img.img);
}

void	init_assets(t_data *d)
{
	init_asset_sheet(d->mlx_ptr, &d->assets.player, XPM_PLAYER,
		ft_new_point(64, 64));
	init_asset_sheet(d->mlx_ptr, &d->assets.tiles, XPM_TILESET,
		ft_new_point(32, 32));
}
