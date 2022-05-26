/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 06:18:55 by mykman            #+#    #+#             */
/*   Updated: 2022/05/25 00:08:50 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	read_map(int fd)
{
	char	*line;
	int		ret;
	int		i;

	line = NULL;
	ret = 1;
	i = 0;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
			ft_error("GNL error");
		if (i == 0 && line[0] == '.')
			ft_printf("Bonus file\n");
		free(line);
		i++;
	}
}

void	parse_map(t_data *d, const char *filename)
{
	int		fd;

	if (!ft_strendwith(filename, ".ber"))
		ft_error("Wrong filetype (extension)");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("File not found");
	read_map(fd);
	(void)d;
	// d->map.map = tab;
	// d->map.size.x = ft_strlen(d->map.map[0]);
	// d->map.size.y = ft_tablen(d->map.map);
}
