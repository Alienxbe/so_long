/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 06:12:21 by mykman            #+#    #+#             */
/*   Updated: 2022/05/24 07:27:53 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_tile(t_data d, t_asset asset, int id, t_point pos)
{
	if (id >= asset.count || !asset.list[id].img)
		return ;
	pos.x = pos.x * TILE_SIZE + (TILE_SIZE - asset.list[id].size.x) / 2;
	pos.y = pos.y * TILE_SIZE + TILE_SIZE - asset.list[id].size.y;
	mlx_put_image_to_window(d.mlx_ptr, d.mlx_win, asset.list[id].img, pos.x,
		pos.y);
}