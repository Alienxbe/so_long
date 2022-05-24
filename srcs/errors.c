/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 06:13:02 by mykman            #+#    #+#             */
/*   Updated: 2022/05/24 07:25:03 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(const char *error_msg)
{
	ft_fprintf(STDERR_FILENO, "Error : %s\n", error_msg);
	exit(1);
}

void	exit_game(t_data *d)
{
	int	i;

	i = -1;
	while (++i < d->assets.tiles.count)
		if (d->assets.tiles.list[i].img)
			mlx_destroy_image(d->mlx_ptr, d->assets.tiles.list[i].img);
	i = -1;
	while (++i < d->assets.player.count)
		if (d->assets.player.list[i].img)
			mlx_destroy_image(d->mlx_ptr, d->assets.player.list[i].img);
	free(d->assets.tiles.list);
	free(d->assets.player.list);
	mlx_destroy_window(d->mlx_ptr, d->mlx_win);
	exit(0);
}
