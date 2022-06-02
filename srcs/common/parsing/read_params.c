/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:57:51 by mykman            #+#    #+#             */
/*   Updated: 2022/06/02 23:34:19 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	get_next_param(char **line, int *val)
{
	if (**line != '.')
		return ;
	*val = ft_atoi(++*line);
	*line += ft_strtypelen(*line, &ft_isdigit);
}

char	*read_params(t_file f, t_map *map)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = get_next_line(f.fd, &line);
	if (ret < 0)
		ft_error("GNL error");
	if (line[0] == '.')
	{
		if (f.ext != ext_aer)
			ft_error("File type doesn't support parameters");
		get_next_param(&line, &map->id_size);
		get_next_param(&line, &map->layer_count);
		if (*line) // If there more than params on the line
			ft_error("Map format error");
	}
	if (map->id_size <= 0 || map->layer_count <= 0)
		ft_error("Map format error");
	return (line);
}
