/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 06:11:05 by mykman            #+#    #+#             */
/*   Updated: 2022/06/21 16:23:45 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

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
	count = (t_point){img.size.x / size.x, img.size.y / size.y};
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
	ft_printf("Assets init\n");
	if (entity_get_type(d->entities, entity_player))
		init_asset_sheet(d->mlx_ptr,
			&entity_get_type(d->entities, entity_player)->sprites, PLAYER_XPM, (t_point){64, 64});
	init_asset_sheet(d->mlx_ptr, &d->assets.tiles, TILESET_XPM, (t_point){d->map.tile_size, d->map.tile_size});
}
