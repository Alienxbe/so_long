/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:08:06 by maykman           #+#    #+#             */
/*   Updated: 2022/05/28 13:13:33 by mykman           ###   ########.fr       */
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

static t_map	generate_map(char **argv)
{
	t_map	map;
	int		i;
	int		j;

	map.size = (t_point){ft_atoi(argv[1]), ft_atoi(argv[2])};
	map.id_size = ft_atoi(argv[3]);
	map.layer_count = ft_atoi(argv[4]);
	map.tile_size = ft_atoi(argv[5]);
	map.layers = (t_layer *)malloc(sizeof(t_layer) * map.layer_count);
	if (!map.layers)
		ft_error("Malloc error");
	i = -1;
	while (++i < map.layer_count)
	{
		map.layers[i] = (t_layer)malloc(sizeof(int *) * map.size.y);
		if (!map.layers[i])
			ft_error("Malloc error");
		j = -1;
		while (++j < map.size.y)
		{
			map.layers[i][j] = (int *)ft_calloc(map.size.x, sizeof(int));
			if (!map.layers[i][j])
				ft_error("Malloc error");
		}
	}
	return (map);
}

void	key_actions(t_data *d)
{
	if (d->game.key_active[key_esc])
		exit_game(d);
	if (d->game.key_active[key_tab])
		ft_printf("!tab\n");
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
	print_layer(d.map);
	init_win(&d, d.map.size.x, d.map.size.y, "Map Builder");
	init_keycode(&d);
	init_assets(&d);
	d.func.draw = &draw;
	d.func.key_actions = &key_actions;
	mlx_hook(d.mlx_win, 2, 1L << 0, &key_pressed, &d);
	mlx_hook(d.mlx_win, 3, 1L << 1, &key_released, &d);
	mlx_loop_hook(d.mlx_ptr, &update, &d);
	mlx_loop(d.mlx_ptr);
	exit_game(&d);
}

