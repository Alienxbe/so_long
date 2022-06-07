/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_read_layer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:29:09 by mykman            #+#    #+#             */
/*   Updated: 2022/06/07 18:06:00 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	parse_char(t_map map, int *tab, int x, char *line)
{
	
}

// t_point size, int id_size = t_map
static int	*parse_line(t_map map, char *line, t_parse_char parse_char)
{
	int	*tab;
	int	x;		// Real value of x

	if ((int)ft_strlen(line) / map.id_size != map.size.x)
		return (NULL);
	tab = (int *)malloc(sizeof(int) * map.size.x);
	if (!tab)
		return (NULL);
	x = 0;
	while (line[x * map.id_size])
		parse_char(map, tab, x++, line);
	return (tab);
}

// Should use t_map
t_layer	read_layer(t_file f, t_map map, char *line, t_parse_char f)
{
	t_layer	layer;
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
	return (layer);
}
