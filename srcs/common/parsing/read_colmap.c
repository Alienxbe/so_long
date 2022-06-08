/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_colmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:57:57 by mykman            #+#    #+#             */
/*   Updated: 2022/06/08 17:25:27 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

/*
** Reading collision ruleset
** 1. Map defined
** 	- By ID definition
** 	- By map definition
** 2. Map not defined
** 	-> Need to define using layer
*/

static t_layer	layer_to_col(t_layer layer, t_point size)
{
	t_layer	col;
	int		y;
	int		x;

	col = (t_layer)malloc(sizeof(int *) * size.y);
	if (!col)
		ft_error("Malloc error");
	y = -1;
	while (++y < size.y)
	{
		col[y] = (int *)malloc(sizeof(int) * size.x);
		if (!col[y])
			ft_error("Malloc error");
		x = -1;
		while (++x < size.x)
			col[y][x] = (layer[y][x] != 0);
	}
	return (col);
}

static void	parse_char(t_map *map, int *tab, t_point pos, char *line)
{
	(void)map;
	if (line[pos.x] == 'S')
		tab[pos.x] = 1;
	else if (line[pos.x] == 'T')
		tab[pos.x] = 0;
	else
		ft_error("Wrong char in map");
}

static t_layer	mapid_to_col(t_file f, t_map *map, char *line)
{
	t_layer	layer;

	map->id_size = 1;
	layer = read_layer(f, map, line, &parse_char);
	return (layer);
}

// t_layer	dicid_to_col(t_map *map)
// {
	
// }

void	read_colmap(t_file f, t_map *map, char *line)
{
	if (ft_strncmp(line, "#COL", 5)) // No COL definition
	{
		map->col = layer_to_col(map->layers[0], map->size);
		free(line);
	}
	else
	{
		free(line);
		if (get_next_line(f.fd, &line) < 0)
			ft_error("GNL error");
		if (ft_strtypelen(line, &ft_isdigit))
			ft_printf("ID definition...\n");
		else
			map->col = mapid_to_col(f, map, line);
	}
	(void)map;
	(void)f;
}