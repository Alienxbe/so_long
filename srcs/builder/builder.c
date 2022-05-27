/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:08:06 by maykman           #+#    #+#             */
/*   Updated: 2022/05/27 17:36:41 by maykman          ###   ########.fr       */
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

static int	update(t_data *d)
{
	clock_t	animation_time;

	animation_time = clock();
	if (d->game.key_active[key_esc])
		exit_game(d);
	if (d->game.key_active[key_tab])
		ft_printf("!tab\n");
	draw_builder(d);
	d->game.fps = ajust_frame_rate(clock() - animation_time);
	return (0);
}

int main(int argc, char **argv) // (width, height, id_size, layer_count, tile_size, filename)
{
	t_data	d;

	if (argc != 7)
		ft_error("Wrong argument count");
	ft_bzero(&d, sizeof(t_data));
	d.map = generate_map(argv);
	print_layer(d.map);
	init_win(&d, d.map.size.x, d.map.size.y, "Map Builder");
	init_keycode(&d);
	init_assets(&d);
	mlx_hook(d.mlx_win, 2, 1L << 0, &key_pressed, &d);
	mlx_hook(d.mlx_win, 3, 1L << 1, &key_released, &d);
	mlx_loop_hook(d.mlx_ptr, &update, &d);
	mlx_loop(d.mlx_ptr);
	exit_game(&d);
}

