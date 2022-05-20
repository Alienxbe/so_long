/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 06:12:21 by mykman            #+#    #+#             */
/*   Updated: 2022/05/21 00:19:59 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_tile(t_data d, t_img img, int x, int y)
{
	x = x * TILE_SIZE + (TILE_SIZE - img.width) / 2;
	y = y * TILE_SIZE + TILE_SIZE - img.height;
	mlx_put_image_to_window(d.mlx_ptr, d.mlx_win, img.img, x, y);
}
