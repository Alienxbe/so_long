/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_dicid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:25:48 by mykman            #+#    #+#             */
/*   Updated: 2022/06/10 14:24:58 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	*parse_line(char *line)
{
	int	*tab;
	int	i;
	int	j;

	tab = (int *)malloc(sizeof(int) * (ft_strcount(line, ',') + 2));
	if (!tab)
		ft_error("Malloc error");
	i = 2;
	while (ft_isspace(line[i]))
		i++;
	j = 0;
	while (line[i])
	{
		if (line[i] == ',' && line[i + 1] == ' ')
			i += 2;
		tab[j] = ft_atoi(line + i);
		if (tab[j] < 0)
			ft_error("Wrong collision rule");
		i += ft_strtypelen(line + i, &ft_isdigit);
		j++;
	}
	if (j != ft_strcount(line, ',') + 1)
		ft_error("Wrong collision rule");
	tab[j] = -1;
	free(line);
	return (tab);
}

static int	get_val_id(t_map *map, t_point pos)
{
	int	i;

	i = -1;
	while (map->s_id[++i] >= 0)
		if (map->layers[0][pos.y][pos.x] == map->s_id[i])
			return (1);
	i = -1;
	while (map->t_id[++i] >= 0)
		if (map->layers[0][pos.y][pos.x] == map->t_id[i])
			return (0);
	return (0);
}

t_layer	dicid_to_col(t_file f, t_map *map, char *line)
{
	t_layer	layer;

	map->s_id = parse_line(line);
	if (get_next_line(f.fd, &line) < 0)
		ft_error("GNL error");
	map->t_id = parse_line(line);
	layer = map_to_col(map, &get_val_id);
	free(map->t_id);
	free(map->s_id);
	return (layer);
}
