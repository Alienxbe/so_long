/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:44:40 by maykman           #+#    #+#             */
/*   Updated: 2022/06/22 19:52:26 by mykman           ###   ########.fr       */
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

static void	print_types(void *e)
{
	if (!e)
		return ;
	ft_printf("x: %d\ty: %d\n", ((t_entity *)e)->pos.x, ((t_entity *)e)->pos.y);
}

int	main(int argc, char **argv) // (filename)
{
	t_data	d;

	if (argc != 2)
		ft_error("Wrong argument count");
	ft_bzero(&d, sizeof(t_data));
	parse(&d, argv[1]);
	init_win(&d, WIN_NAME);
	init_assets(&d);
	init_keycode(&d);

	ft_printf("entity list size: %d\n", ft_lstsize(d.entities));
	ft_printf("type: %d\n", ((t_entity *)d.entities->content)->type);
	ft_printf("player: %d\n", entity_get_type(d.entities, entity_player)->type);
	ft_lstiter(d.entities, &print_types);

	mlx_hook(d.mlx_win, 2, 1L << 0, &key_pressed, &d);
	mlx_hook(d.mlx_win, 3, 1L << 1, &key_released, &d);
	mlx_hook(d.mlx_win, 17, 0, &exit_game, &d);
	mlx_loop_hook(d.mlx_ptr, &update, &d);
	mlx_loop(d.mlx_ptr);
	exit_game(&d);
}
