/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 06:12:21 by mykman            #+#    #+#             */
/*   Updated: 2022/05/23 20:02:56 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_tile(t_data d, t_img img, int x, int y)
{
	x = x * TILE_SIZE + (TILE_SIZE - img.size.x) / 2;
	y = y * TILE_SIZE + TILE_SIZE - img.size.y;
	mlx_put_image_to_window(d.mlx_ptr, d.mlx_win, img.img, x, y);
}
