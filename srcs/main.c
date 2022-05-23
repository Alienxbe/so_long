/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:44:40 by maykman           #+#    #+#             */
/*   Updated: 2022/05/23 22:59:35 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	test_map(t_data d)
// {
// 	for (int y = 0; y <= WIN_HEIGHT / TILE_SIZE; y++)
// 	{
// 		for (int x = 0; x <= WIN_WIDTH / TILE_SIZE; x++)
// 		{
// 			if (!((x * y) % 15))
// 				set_tile(d, d.assets[grassy_grass], x, y);
// 			else if (!((x * y) % 20))
// 				set_tile(d, d.assets[pkmn_grass], x, y);
// 			else if (((x * y) % 15) == 2)
// 				set_tile(d, d.assets[flower1_grass], x, y);
// 			else if (((x * y) % 20) == 2)
// 				set_tile(d, d.assets[flower2_grass], x, y);
// 			else
// 				set_tile(d, d.assets[grass], x, y);
// 		}
// 	}
// 	for (int y = 0; y < 3; y++)
// 		for (int x = 0; x < 3; x++)
// 			set_tile(d, d.assets[pkmn_grass], x + 7, y + 5);
// 	set_tile(d, d.assets[sign], 10, 6);
// 	set_tile(d, d.assets[red], 11, 7);
// 	set_tile(d, d.assets[red], 1, 5);
// 	set_tile(d, d.assets[p1_front], 2, 6);
// }

int	main(void)
{
	t_data	d;

	init_win(&d);
	init_assets(&d);
	test_map(d);
	mlx_loop(d.mlx_ptr);
	mlx_destroy_window(d.mlx_ptr, d.mlx_win);
	exit(0);
}
