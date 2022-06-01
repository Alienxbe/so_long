/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 12:51:06 by mykman            #+#    #+#             */
/*   Updated: 2022/05/30 22:54:54 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(t_data *d)
{
	mlx_clear_window(d->mlx_ptr, d->mlx_win);
	for (int y = 0; y < d->map.size.y; y++)
		for (int x = 0; x < d->map.size.x; x++)
			set_tile(d, d->assets.tiles, d->map.layers[0][y][x], (t_point){x, y});
	// rendering player
	set_tile(d, d->assets.player, d->game.player.frame / (FRAME_PER_ANIMATION) + d->game.player.rot * 4, (t_point){d->game.player.pos.x, d->game.player.pos.y});
}
