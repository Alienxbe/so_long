/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_colmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:57:57 by mykman            #+#    #+#             */
/*   Updated: 2022/06/15 12:53:24 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	get_val_map(t_map *map, t_point pos)
{
	return ((map->layers[0][pos.y][pos.x] != 0));
}

void	read_colmap(t_file f, t_map *map, char *line)
{
	if (ft_strncmp(line, "#COL", 5)) // No COL definition
	{
		map->col = map_to_col(map, &get_val_map);
		free(line);
	}
	else
	{
		free(line);
		if (get_next_line(f.fd, &line) < 0)
			ft_error("GNL error");
		map->col = mapid_to_col(f, map, line);
	}
}