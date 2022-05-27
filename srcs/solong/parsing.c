/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 06:18:55 by mykman            #+#    #+#             */
/*   Updated: 2022/05/27 15:31:04 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	parse_param(t_data *d, t_file f, char *line)
{
	if (f.ext != ext_aer)
		ft_error("Map extension cannot have parameters");
	d->map.id_size = ft_atoi(++line);
	line += ft_strtypelen(line, &ft_isdigit);
	if (*line == '.')
		d->map.layer_count = ft_atoi(++line);
}

static int	*parse_line(t_data *d, char *line)
{
	int	*tab;
	int	i;

	if ((int)ft_strlen(line) != d->map.size.x)
		ft_error("Map format is wrong");
	tab = (int *)malloc(sizeof(int) * d->map.size.x);
	if (!tab)
		ft_error("Malloc error");
	i = -1;
	while (line[++i])
	{
		if (ft_strchr(TILES_X_LIST, line[i]))
			tab[i] = MAX_TILE_ID + ft_index(TILES_X_LIST, line[i]);
		else if (ft_isdigit(line[i]) && ft_atoi_l(line, d->map.id_size) < MAX_TILE_ID)
			tab[i] = ft_atoi_l(line + i, d->map.id_size);
		else
			ft_error("Wrong character in map");
	}
	return (tab);
}

static t_layer	copy_layer(t_data *d, t_list **lst)
{
	t_layer	layer;
	t_list	*ptr;
	int		i;

	layer = (t_layer)malloc(sizeof(int *) * d->map.size.y);
	if (!layer)
		ft_error("Malloc error");
	ptr = *lst;
	i = 0;
	while (ptr)
	{
		layer[i++] = (int *)ptr->content;
		ptr = ptr->next;
	}
	ft_lstclear(lst, NULL);
	return (layer);
}

static t_layer	parse_layer(t_data *d, t_file f, char *first_line)
{
	t_list	*lst;
	t_list	*new_lst;
	char	*line;
	int		ret;

	lst = NULL;
	line = first_line;
	d->map.size.x = ft_strlen(line) / d->map.id_size;
	if (ft_strlen(first_line) % d->map.id_size)
		ft_error("Map format is wrong");
	while (*line || ret)
	{
		new_lst = ft_lstnew(parse_line(d, line));
		free(line);
		if (!new_lst)
			ft_error("Malloc error");
		ft_lstadd_back(&lst, new_lst);
		ret = get_next_line(f.fd, &line);
		if (ret < 0)
			ft_error("GNL error");
	}
	d->map.size.y = ft_lstsize(lst);
	return (copy_layer(d, &lst));
}

static void	read_map(t_data *d, t_file f)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (i < d->map.layer_count)
	{
		if (get_next_line(f.fd, &line) <= 0)
			ft_error("GNL error");
		if (i == 0)
		{
			if (line[0] == '.')
			{
				parse_param(d, f, line);
				free(line);
				if (get_next_line(f.fd, &line) <= 0)
					ft_error("GNL error");
			}
			d->map.layers = (t_layer *)ft_calloc(d->map.layer_count, sizeof(t_layer));
			if (!d->map.layers)
				ft_error("Malloc error");
		}
		d->map.layers[i] = parse_layer(d, f, line);
		i++;
	}
}

static t_file_extension	get_extension(const char *filename)
{
	if (ft_strendwith(filename, ".ber"))
		return (ext_ber);
	else if (ft_strendwith(filename, ".aer"))
		return (ext_aer);
	return (ext_error);
}

void	parse_map(t_data *d, const char *filename)
{
	t_file	f;
	
	f.filename = filename;
	f.fd = open(filename, O_RDONLY);
	if (f.fd < 0)
		ft_error("File not found");
	f.ext = get_extension(filename);
	if (f.ext < 0)
		ft_error("Wrong extension type");
	d->map.id_size = 1;
	d->map.layer_count = 1;
	read_map(d, f);
	d->map.tile_size = 32;
	d->win_size = (t_point){d->map.size.x * TILE_SIZE, d->map.size.y * TILE_SIZE};
}