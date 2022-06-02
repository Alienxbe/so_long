/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 06:12:21 by mykman            #+#    #+#             */
/*   Updated: 2022/06/02 21:28:44 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	set_tile(t_data *d, t_asset asset, int id, t_point pos)
{
	if (id >= asset.count || !asset.list[id].img)
		return ;
	pos.x = pos.x * d->map.tile_size + (d->map.tile_size - asset.list[id].size.x) / 2;
	pos.y = pos.y * d->map.tile_size + d->map.tile_size - asset.list[id].size.y;
	// if (pos.x < 0 || pos.x > d.win_size.x || pos.y < 0 || pos.y > d.win_size.y)
	// 	return ;
	mlx_put_image_to_window(d->mlx_ptr, d->mlx_win, asset.list[id].img, pos.x,
		pos.y);
}
