/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:57:07 by maykman           #+#    #+#             */
/*   Updated: 2022/05/29 00:08:49 by mykman           ###   ########.fr       */
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

void	show_fps(t_data *d)
{
	char	*fps_str;

	fps_str = ft_itoa(d->game.fps);
	if (!fps_str)
		ft_error("Malloc error");
	mlx_string_put(d->mlx_ptr, d->mlx_win, 10, 15, 0, fps_str);
	free(fps_str);
}

int	update(t_data *d)
{
	clock_t	animation_time;

	animation_time = clock();
	key_actions(d);
	draw(d);
	if (SHOW_FPS)
		show_fps(d);
	d->game.fps = ajust_frame_rate(clock() - animation_time);
	return (0);
}
