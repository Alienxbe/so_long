/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_layers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 03:04:13 by mykman            #+#    #+#             */
/*   Updated: 2022/06/10 14:22:09 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	parse_char(t_map *map, int *tab, t_point pos, char *line)
{

	int	i;

	i = pos.x * map->id_size;
	if (line[i + map->id_size - 1] == 'x')
		tab[pos.x] = -1;
	else if ((int)ft_strtypelen(line + i, &ft_isdigit) >= map->id_size)
		tab[pos.x] = ft_atoi_l(line + i, map->id_size);
	else
		ft_error("Wrong character in map");
}

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
		map->layers[i] = read_layer(f, map, line, &parse_char);
		if (get_next_line(f.fd, &line) < 0) // Read the first line of the next layer
			ft_error("GNL error");
	}
	return (line);
}
