/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_layers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 03:04:13 by mykman            #+#    #+#             */
/*   Updated: 2022/06/07 09:39:23 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

char	*read_layers(t_file f, t_map *map, char *line)
{
	int	i;

	map->layers = (t_layer *)ft_calloc(map->layer_count, sizeof(t_layer));
	if (!map->layers)
		ft_error("Malloc error");
	map->size.x = ft_strlen(line) / map->id_size;
	i = -1;
	while (++i < map->layer_count)
	{
		map->layers[i] = read_layer(f, map, line);
		if (get_next_line(f.fd, &line) < 0) // Read the first line of the next layer
			ft_error("GNL error");
	}
	return (line);
}
