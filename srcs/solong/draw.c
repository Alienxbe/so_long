/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 12:51:06 by mykman            #+#    #+#             */
/*   Updated: 2022/05/28 12:51:16 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(t_data *d)
{
	mlx_clear_window(d->mlx_ptr, d->mlx_win);
	for (int y = 0; y < d->map.size.y; y++)
		for (int x = 0; x <= d->map.size.x; x++)
			set_tile(d, d->assets.tiles, grass, (t_point){x, y});
	// for (int i=0; i < 200; i++)
	// 	set_tile(*d, d->assets.tiles, i + 100, (t_point){i % 8, i / 8});
	// for (int i = 0; i < 16; i++)
	// 	set_tile(*d, d->assets.tiles, grass_pkmn, ft_new_point(5 + i % 4, 5 + i / 4));
	for (int y = 0; y < d->map.size.y; y++)
		for (int x = 0; x < d->map.size.x; x++)
		{
			// if (d->map.layers[0][y][x] == 1)
			// 	d->map.layers[0][y][x] = 141;
			// if (d->map.layers[0][y][x] == 2)
			// 	d->map.layers[0][y][x] = 143;
			// if (d->map.layers[0][y][x] == 5)
			// 	d->map.layers[0][y][x] = 137;
			// if (d->map.layers[0][y][x] == 6)
			// 	d->map.layers[0][y][x] = 139;
			// if (d->map.layers[0][y][x] == 7)
			// 	d->map.layers[0][y][x] = 153;
			// if (d->map.layers[0][y][x] == 8)
			// d->map.layers[0][y][x] = 155;
			set_tile(d, d->assets.tiles, d->map.layers[0][y][x], (t_point){x, y});
		}
	// for (int i = 0; i < 4; i++)
	// 	set_tile(*d, d->assets.tiles, 146, (t_point){1 + i, 4});
	// rendering player
	for (int i = 0; i < 4; i++)
		set_tile(d, d->assets.player, d->game.player.frame / (FRAME_PER_ANIMATION) + d->game.player.rot * 4, (t_point){d->game.player.pos.x + i, d->game.player.pos.y + i});
}
