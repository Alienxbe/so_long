/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 13:54:08 by mykman            #+#    #+#             */
/*   Updated: 2022/06/20 18:09:07 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	add_animation_frame(t_entity *e)
{
	e->frame++;
	if (e->frame >= 4 * FRAME_PER_ANIMATION)
		e->frame = 0;
}

void	key_actions(t_data *d)
{
	t_entity	*player;
	int	active_key_count;

	if (d->game.key_active[key_esc])
		exit_game(d);
	player = entity_get_type(d->entities, entity_player);
	active_key_count = 0;
	if (player->frame == 0 || d->game.player.frame == 2 * FRAME_PER_ANIMATION)
	{
		for (int i = 0; i <= key_up; i++)
		{
			if (d->game.key_active[i])
			{
				active_key_count++;
				player->rot = i;
				add_animation_frame(player);	
				break;
			}
		}
	}
	else
		add_animation_frame(player);
}
