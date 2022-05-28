/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 13:54:08 by mykman            #+#    #+#             */
/*   Updated: 2022/05/28 13:55:41 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	add_animation_frame(t_data *d)
{
	d->game.player.frame++;
	if (d->game.player.frame >= 4 * FRAME_PER_ANIMATION)
		d->game.player.frame = 0;
}

void	key_actions(t_data *d)
{
	int	active_key_count;

	if (d->game.key_active[key_esc])
		exit_game(d);
	active_key_count = 0;
	if (d->game.player.frame == 0 || d->game.player.frame == 2 * FRAME_PER_ANIMATION)
	{
		for (int i = 0; i <= key_up; i++)
		{
			if (d->game.key_active[i])
			{
				active_key_count++;
				d->game.player.rot = i;
				add_animation_frame(d);	
				break;
			}
		}
	}
	else
		add_animation_frame(d);
}
