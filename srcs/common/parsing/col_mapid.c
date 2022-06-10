/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_mapid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:25:48 by mykman            #+#    #+#             */
/*   Updated: 2022/06/10 13:27:24 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	parse_char(t_map *map, int *tab, t_point pos, char *line)
{
	(void)map;
	if (line[pos.x] == '1' || line[pos.x] == 'S')
		tab[pos.x] = 1;
	else if (line[pos.x] == '0' || line[pos.x] == 'T')
		tab[pos.x] = 0;
	else
		ft_error("Wrong char in map");
}

t_layer	mapid_to_col(t_file f, t_map *map, char *line)
{
	t_layer	layer;

	map->id_size = 1;
	layer = read_layer(f, map, line, &parse_char);
	return (layer);
}
