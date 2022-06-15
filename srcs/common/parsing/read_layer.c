/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_layer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:29:09 by mykman            #+#    #+#             */
/*   Updated: 2022/06/08 17:25:17 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	*parse_line(t_map *map, char *line, t_point pos, t_fparsec fpc)
{
	int	*tab;

	if ((int)ft_strlen(line) / map->id_size != map->size.x)
		ft_error("Wrong line size");
	tab = (int *)malloc(sizeof(int) * map->size.x);
	if (!tab)
		ft_error("Malloc error");
	while (line[pos.x * map->id_size])
	{
		fpc(map, tab, pos, line);
		pos.x++;
	}
	free(line);
	return (tab);
}

static t_layer	build_layer(t_map *map, t_list *lst, int y)
{
	t_layer	layer;
	t_list	*tmp;
	int		i;

	if (!map->size.y)
		map->size.y = y;
	if (!map->size.y || map->size.y != ft_lstsize(lst))
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

t_layer	read_layer(t_file f, t_map *map, char *line, t_fparsec fpc)
{
	t_list	*lst;
	t_list	*new;
	int		y;

	lst = NULL;
	y = 0;
	while (*line)
	{
		new = ft_lstnew(parse_line(map, line, (t_point){0, y}, fpc));
		if (!new)
			ft_error("Malloc error");
		ft_lstadd_back(&lst, new);
		if (get_next_line(f.fd, &line) < 0) // Read next line
			ft_error("GNL error");
		y++;
	}
	free(line);
	return (build_layer(map, lst, y));
}
