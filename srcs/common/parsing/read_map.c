/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:27:56 by mykman            #+#    #+#             */
/*   Updated: 2022/06/02 22:42:34 by mykman           ###   ########.fr       */
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
	char	*line;
	
	init_map(&map);
	line = read_params(f, &map);
	PRINT_VAR(map.id_size, "d");
	PRINT_VAR(map.layer_count, "d");
	// read_layers();
	// read_colmap();
	return (map);
}
