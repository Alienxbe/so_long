/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 12:51:06 by mykman            #+#    #+#             */
/*   Updated: 2022/06/20 18:06:42 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(t_data *d)
{
	t_entity	*player;

	for (int layer = 0; layer < d->map.layer_count; layer++)
		for (int y = 0; y < d->map.size.y; y++)
			for (int x = 0; x < d->map.size.x; x++)
				set_tile(d, d->assets.tiles, d->map.layers[layer][y][x], (t_point){x, y});
	// rendering player
	// set_tile(d, d->assets.player, d->game.player.frame / (FRAME_PER_ANIMATION) + d->game.player.rot * 4, (t_point){d->game.player.pos.x, d->game.player.pos.y});
	player = entity_get_type(d->entities, entity_player);
	set_tile(d, player->sprites, player->frame / (FRAME_PER_ANIMATION) + player->rot * 4, player->pos);
}
