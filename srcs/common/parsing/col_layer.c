/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_layer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:28:07 by mykman            #+#    #+#             */
/*   Updated: 2022/06/10 13:28:24 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_layer	map_to_col(t_map *map, int (*get_value)(t_map *, t_point))
{
	t_layer	col;
	t_point	pos;

	col = (t_layer)malloc(sizeof(int *) * map->size.y);
	if (!col)
		ft_error("Malloc error");
	pos.y = -1;
	while (++pos.y < map->size.y)
	{
		col[pos.y] = (int *)malloc(sizeof(int) * map->size.x);
		if (!col[pos.y])
			ft_error("Malloc error");
		pos.x = -1;
		while (++pos.x < map->size.x)
			col[pos.y][pos.x] = get_value(map, pos);
	}
	return (col);
}
