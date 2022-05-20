/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 06:12:21 by mykman            #+#    #+#             */
/*   Updated: 2022/05/20 06:12:39 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_tile(t_data d, t_img img, int x, int y)
{
	x = x * TILE_SIZE + TILE_SIZE - img.width;
	y = y * TILE_SIZE + TILE_SIZE - img.height;
	mlx_put_image_to_window(d.mlx_ptr, d.mlx_win, img.img, x, y);
}
