/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:20:28 by maykman           #+#    #+#             */
/*   Updated: 2022/05/28 18:25:29 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builder.h"

void	draw(t_data *d)
{
	char	*fps_str;

	for (int l = 0; l < d->map.layer_count; l++)
		for (int y = 0; y < d->map.size.y; y++)
			for (int x = 0; x < d->map.size.x; x++)
					set_tile(d, d->assets.tiles, d->map.layers[l][y][x],
						(t_point){x, y});
	fps_str = ft_itoa(d->game.fps);
	if (SHOW_FPS)
	{
		if (!fps_str)
			ft_error("Malloc error");
		mlx_string_put(d->mlx_ptr, d->mlx_win, 10, 15, 0, fps_str);
		free(fps_str);
	}
}
