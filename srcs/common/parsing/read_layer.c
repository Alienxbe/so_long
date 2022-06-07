/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_layer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 04:05:12 by mykman            #+#    #+#             */
/*   Updated: 2022/06/07 08:40:53 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	set_pos(t_point *p, int x, int y)
{
	if (p->x || p->y)
		ft_error("Map format is wrong");
	p->x = x;
	p->y = y;
}

static int	*parse_line(t_map *map, char *line, int y)
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
		tab[i / map->id_size] = -1 * (map->layer_count > 1);
		if (line[i + map->id_size - 1] == 'P')
			set_pos(&map->pos_p, i / map->id_size, y); // Set player pos
		else if (line[i + map->id_size - 1] == 'C')
			set_pos(&map->pos_c, i / map->id_size, y); // Set coin pos
		else if (line[i + map->id_size - 1] == 'E')
			set_pos(&map->pos_e, i / map->id_size, y); // Set exit pos
		else if (line[i + map->id_size - 1] == 'x')
			tab[i / map->id_size] = NO_TILE; // Do nothing
		else if ((int)ft_strtypelen(line + i, &ft_isdigit) >= map->id_size)
			tab[i / map->id_size] = ft_atoi_l(line + i, map->id_size);
		else
			ft_error("Wrong character in map");
		i += map->id_size;
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

t_layer	read_layer(t_file f,t_map *map, char *line)
{
	t_list	*lst;
	t_list	*new;
	int		y;

	lst = NULL;
	y = 0;
	while (*line)
	{
		new = ft_lstnew(parse_line(map, line, y));
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
