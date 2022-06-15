/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:08:06 by maykman           #+#    #+#             */
/*   Updated: 2022/06/15 13:11:22 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builder.h"

static void	print_layer(t_map map)
{
	t_layer layer;

	layer = map.layers[0];
	for (int y = 0; y < map.size.y; y++)
	{
		for (int x = 0; x < map.size.x; x++)
			ft_printf("%d ", layer[y][x]);
		ft_printf("\n");
	}
}

int main(int argc, char **argv) // (width, height, id_size, layer_count, tile_size, filename)
{
	t_data	d;

	ft_bzero(&d, sizeof(t_data));
	if (argc != 7)
	{
		ft_printf("Usage: ./builder [Width] [Height] [Id size] [Layer count] [Tile size] [Filename]\n");
		exit_game(&d);
	}
	d.map = generate_map(argv);
	d.win_size = (t_point){d.map.size.x * d.map.tile_size, d.map.size.y * d.map.tile_size};
	print_layer(d.map);
	init_win(&d, "Map Builder");
	init_keycode(&d);
	init_assets(&d);
	mlx_hook(d.mlx_win, 2, 1L << 0, &key_pressed, &d);
	mlx_hook(d.mlx_win, 3, 1L << 1, &key_released, &d);
	mlx_loop_hook(d.mlx_ptr, &update, &d);
	mlx_loop(d.mlx_ptr);
	exit_game(&d);
}

