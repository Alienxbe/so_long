/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 06:18:55 by mykman            #+#    #+#             */
/*   Updated: 2022/05/20 07:25:15 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(t_data *d, const char *filename)
{
	char	buff[BUFFER_SIZE];
	char	*file;
	char	**lines;
	int		fd;

	if (!ft_strendwith(filename, ".ber"))
		ft_error("Wrong filetype (extension)");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("File not found");
	file = (char *)1;
	while (read(fd, buff, BUFFER_SIZE) > 0 && file)
		file = gnl_strjoin(file, buff);
	lines = ft_split(file, '\n');
	if (!lines)
		ft_error("Malloc error");
}
