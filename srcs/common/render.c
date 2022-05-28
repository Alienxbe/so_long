/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:57:07 by maykman           #+#    #+#             */
/*   Updated: 2022/05/28 18:25:51 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ajust_frame_rate(int animation_time)
{
	if (animation_time < (CLOCKS_PER_SEC / FPS_MAX))
	{
		usleep((CLOCKS_PER_SEC / FPS_MAX) - animation_time);
		animation_time = (CLOCKS_PER_SEC / FPS_MAX);
	}
	return (CLOCKS_PER_SEC / animation_time);
}

int	update(t_data *d)
{
	clock_t	animation_time;

	animation_time = clock();
	key_actions(d);
	draw(d);
	d->game.fps = ajust_frame_rate(clock() - animation_time);
	return (0);
}
