/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 06:18:55 by mykman            #+#    #+#             */
/*   Updated: 2022/06/15 03:31:34 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

// Return the file extension id
static t_file_extension	get_extension(const char *filename)
{
	if (ft_strendwith(filename, ".ber"))
		return (ext_ber);
	else if (ft_strendwith(filename, ".aer"))
		return (ext_aer);
	return (ext_error);
}

static t_file	init_file(const char *filename)
{
	t_file	f;

	f.filename = filename;
	f.fd = open(f.filename, O_RDONLY);
	f.ext = get_extension(f.filename);
	if (f.fd < 0)
		ft_error("File not found");
	if (f.ext == ext_error)
		ft_error("Wrong extension type");
	return (f);
}

// Parse the file
void	parse(t_data *d, const char *filename)
{
	t_file	f;
	
	f = init_file(filename);
	d->map = read_map(f);
	d->game.player.pos = d->map.pos_p;
	d->win_size = (t_point){d->map.size.x * d->map.tile_size, d->map.size.y * d->map.tile_size};
}