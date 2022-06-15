/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:27:56 by mykman            #+#    #+#             */
/*   Updated: 2022/06/15 03:28:22 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	print_layer(t_layer layer, t_point size)
{
	if (!layer)
		return ;
	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
			ft_printf("%3d ",layer[y][x]);
		ft_printf("\n");
	}
}

static void	print_map(t_map map)
{
	for (int i = 0; i < map.layer_count; i++)
	{
		print_layer(map.layers[i], map.size);
		ft_printf("\n");
	}
}

static void	init_map(t_map *map)
{
	ft_bzero(map, sizeof(t_map));
	map->id_size = 1;
	map->layer_count = 1;
}

t_map	read_map(t_file f)
{
	t_map	map;
	char	*line;
	
	init_map(&map);
	line = read_params(f, &map); // Always return the first line of the first layer
	line = read_layers(f, &map, line);
	read_colmap(f, &map, line);
	print_map(map);
	print_layer(map.col, map.size);
	map.tile_size = 32;
	return (map);
}
