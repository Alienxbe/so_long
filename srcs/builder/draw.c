/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:20:28 by maykman           #+#    #+#             */
/*   Updated: 2022/05/28 13:12:22 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builder.h"

void	draw(t_data *d)
{
	for (int l = 0; l < d->map.layer_count; l++)
		for (int y = 0; y < d->map.size.y; y++)
			for (int x = 0; x < d->map.size.x; x++)
					set_tile(d, d->assets.tiles, d->map.layers[l][y][x],
						(t_point){x, y});
}
