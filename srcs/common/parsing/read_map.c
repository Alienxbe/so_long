/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:27:56 by mykman            #+#    #+#             */
/*   Updated: 2022/06/03 10:07:26 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	init_map(t_map *map)
{
	ft_bzero(map, sizeof(t_map));
	map->id_size = 1;
	map->layer_count = 1;
}

t_map	read_map(t_file f)
{
	t_map	map;
	t_layer	layer;
	char	*line;
	
	init_map(&map);
	line = read_params(f, &map); // Always return the first line of the first layer
	map.size.x = ft_strlen(line) / map.id_size;
	layer = read_layer(&map, f, line);
	for (int j = 0; j < map.size.y; j++)
	{
		
		PRINT_TAB(layer[j], map.size.x, "d");
	}
	// read_layers(f, &map, line);
	// read_colmap();
	return (map);
}
