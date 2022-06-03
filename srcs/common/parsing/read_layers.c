/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_layers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 03:04:13 by mykman            #+#    #+#             */
/*   Updated: 2022/06/03 08:48:03 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	read_layers(t_file f, t_map *map, char *line)
{
	map->layers = (t_layer *)ft_calloc(map->layer_count, sizeof(t_layer));
	if (!map->layers)
		ft_error("Malloc error");
	map->size.x = ft_strlen(line);
	(void)f;
	// while () // for each layer
	// {
	// 	// read_layer
	// }
}
