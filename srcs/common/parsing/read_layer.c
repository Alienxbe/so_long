/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_layer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 04:05:12 by mykman            #+#    #+#             */
/*   Updated: 2022/06/03 10:02:32 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	*parse_line(t_map *map, char *line)
{
	int	*tab;
	int	i;

	if ((int)ft_strlen(line) != map->size.x * map->id_size)
		ft_error("Map format is wrong");
	tab = (int *)malloc(sizeof(int) * map->size.x);
	if (!tab)
		ft_error("Malloc error");
	i = 0;
	while (line[i])
	{
		tab[i / map->id_size] = -1;
		if (line[i + map->id_size - 1] == 'P')
			; // Set player pos
		else if (line[i + map->id_size - 1] == 'C')
			; // Set coin pos
		else if (line[i + map->id_size - 1] == 'E')
			; // Set exit pos
		else if ((int)ft_strtypelen(line + i, &ft_isdigit) >= map->id_size)
			tab[i / map->id_size] = ft_atoi_l(line + i, map->id_size);
		else
			ft_error("Wrong character in map");
		i += map->id_size;
	}
	free(line);
	return (tab);
}

static t_layer	build_layer(t_map *map, t_list *lst)
{
	t_layer	layer;
	t_list	*tmp;
	int		i;

	if (!map->size.y)
		map->size.y = ft_lstsize(lst);
	if (!map->size.y)
		ft_error("Map format error");
	else if (map->size.y != ft_lstsize(lst))
		ft_error("Map format error");
	layer = (t_layer)malloc(sizeof(int *) * ft_lstsize(lst));
	if (!layer)
		ft_error("Malloc error");
	i = -1;
	while (++i < map->size.y)
	{
		layer[i] = (int *)lst->content;
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	return (layer);
}

t_layer	read_layer(t_map *map, t_file f, char *line)
{
	t_list	*lst;
	t_list	*new;

	lst = NULL;
	while (*line)
	{
		new = ft_lstnew(parse_line(map, line));
		if (!new)
			ft_error("Malloc error");
		ft_lstadd_back(&lst, new);
		if (get_next_line(f.fd, &line) < 0) // Read next line
			ft_error("GNL error");
	}
	return (build_layer(map, lst));
}