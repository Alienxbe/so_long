/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:44:40 by maykman           #+#    #+#             */
/*   Updated: 2022/06/19 03:59:58 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	print_layer(t_map map)
// {
// 	t_layer layer;

// 	layer = map.layers[0];
// 	for (int y = 0; y < map.size.y; y++)
// 	{
// 		for (int x = 0; x < map.size.x; x++)
// 			ft_printf("%d ", layer[y][x]);
// 		ft_printf("\n");
// 	}
// }

int	main(int argc, char **argv) // (filename)
{
	t_data	d;
	int		ent[10];

	if (argc != 2)
		ft_error("Wrong argument count");
	ft_bzero(&d, sizeof(t_data));
	parse(&d, argv[1]);
	init_win(&d, WIN_NAME);
	init_assets(&d);
	init_keycode(&d);

	ent[0] = new_entity(&d.entities);
	ent[1] = new_entity(&d.entities);
	ent[2] = new_entity(&d.entities);

	get_entity(d.entities, ent[0])->name = "Player";
	get_entity(d.entities, ent[1])->name = "Zez";
	get_entity(d.entities, ent[2])->name = "arbre";

	ft_printf("player id : %p\n", get_entity(d.entities, 5));

	mlx_hook(d.mlx_win, 2, 1L << 0, &key_pressed, &d);
	mlx_hook(d.mlx_win, 3, 1L << 1, &key_released, &d);
	mlx_loop_hook(d.mlx_ptr, &update, &d);
	mlx_loop(d.mlx_ptr);
	exit_game(&d);
}
