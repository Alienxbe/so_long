/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:27:56 by mykman            #+#    #+#             */
/*   Updated: 2022/06/03 17:13:33 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	print_map(t_map map)
{
	for (int i = 0; i < map.layer_count; i++)
	{
		for (int y = 0; y < map.size.y; y++)
		{
			for (int x = 0; x < map.size.x; x++)
				ft_printf("%3d ", map.layers[i][y][x]);
			ft_printf("\n");
		}
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
	read_layers(f, &map, line);
	print_map(map);
	// read_colmap();
	return (map);
}
