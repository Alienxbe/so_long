/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:57:51 by mykman            #+#    #+#             */
/*   Updated: 2022/06/03 04:00:18 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	get_next_param(char *line, int *i, int *val)
{
	if (line[*i] != '.')
		return ;
	*val = ft_atoi(line + ++*i);
	*i += ft_strtypelen(line + *i, &ft_isdigit);
}

char	*read_params(t_file f, t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if (get_next_line(f.fd, &line) < 0)
		ft_error("GNL error");
	if (line[0] == '.')
	{
		if (f.ext != ext_aer)
			ft_error("File type doesn't support parameters");
		get_next_param(line, &i, &map->id_size);
		get_next_param(line, &i, &map->layer_count);
		if (line[i]) // If there more than params on the line
			ft_error("Map format error");
		free(line);
		if (get_next_line(f.fd, &line) < 0)
			ft_error("GNL error");
	}
	if (map->id_size <= 0 || map->layer_count <= 0)
		ft_error("Map format error");
	return (line);
}
