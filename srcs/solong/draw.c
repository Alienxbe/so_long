/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 12:51:06 by mykman            #+#    #+#             */
/*   Updated: 2022/06/21 15:51:26 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(t_data *d)
{
	t_list		*lst;
	t_entity	*e;

	for (int layer = 0; layer < d->map.layer_count; layer++)
	{
		for (int y = 0; y < d->map.size.y; y++)
		{
			for (int x = 0; x < d->map.size.x; x++)
			{
				if (!layer && d->map.layers[layer][y][x] == NO_TILE)
					set_tile(d, d->assets.tiles, 0, (t_point){x, y});
				else
					set_tile(d, d->assets.tiles, d->map.layers[layer][y][x], (t_point){x, y});
			}
		}
	}
	// Rendering entities
	lst = d->entities;
	while (lst)
	{
		e = (t_entity *)lst->content;
		set_tile(d, e->sprites, e->frame / FRAME_PER_ANIMATION + e->rot * 4, e->pos);
		lst = lst->next;
	}
	// rendering player
	// set_tile(d, d->assets.player, d->game.player.frame / (FRAME_PER_ANIMATION) + d->game.player.rot * 4, (t_point){d->game.player.pos.x, d->game.player.pos.y});
}
