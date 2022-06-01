/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:44:40 by maykman           #+#    #+#             */
/*   Updated: 2022/05/29 04:13:16 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	main(int argc, char **argv) // (filename)
{
	t_data	d;

	if (argc != 2)
		ft_error("Wrong argument count");
	ft_bzero(&d, sizeof(t_data));
	d.map.tile_size = 32;
	parse_map(&d, argv[1]);
	print_layer(d.map);
	init_win(&d, d.map.size.x, d.map.size.y, WIN_NAME);
	init_assets(&d);
	init_keycode(&d);
	d.game.player.pos = (t_point){1, 1};
	mlx_hook(d.mlx_win, 2, 1L << 0, &key_pressed, &d);
	mlx_hook(d.mlx_win, 3, 1L << 1, &key_released, &d);
	mlx_loop_hook(d.mlx_ptr, &update, &d);
	ft_putnbr_base_fd(128, "ABCDEFGHIJ", 1);
	mlx_loop(d.mlx_ptr);
	exit_game(&d);
}
