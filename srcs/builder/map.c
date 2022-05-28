/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 13:56:27 by mykman            #+#    #+#             */
/*   Updated: 2022/05/28 13:56:44 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builder.h"

t_map	generate_map(char **argv)
{
	t_map	map;
	int		i;
	int		j;

	map.size = (t_point){ft_atoi(argv[1]), ft_atoi(argv[2])};
	map.id_size = ft_atoi(argv[3]);
	map.layer_count = ft_atoi(argv[4]);
	map.tile_size = ft_atoi(argv[5]);
	map.layers = (t_layer *)malloc(sizeof(t_layer) * map.layer_count);
	if (!map.layers)
		ft_error("Malloc error");
	i = -1;
	while (++i < map.layer_count)
	{
		map.layers[i] = (t_layer)malloc(sizeof(int *) * map.size.y);
		if (!map.layers[i])
			ft_error("Malloc error");
		j = -1;
		while (++j < map.size.y)
		{
			map.layers[i][j] = (int *)ft_calloc(map.size.x, sizeof(int));
			if (!map.layers[i][j])
				ft_error("Malloc error");
		}
	}
	return (map);
}
