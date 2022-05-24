/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 06:13:02 by mykman            #+#    #+#             */
/*   Updated: 2022/05/24 04:09:05 by maykman          ###   ########.fr       */
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
	for (int i = 0; i < d->tiles.count; i++)
		if (d->tiles.list[i].img)
			mlx_destroy_image(d->mlx_ptr, d->tiles.list[i].img);
	free(d->tiles.list);
	for (int i = 0; i < d->player.count; i++)
		if (d->player.list[i].img)
			mlx_destroy_image(d->mlx_ptr, d->player.list[i].img);
	free(d->player.list);
	mlx_destroy_window(d->mlx_ptr, d->mlx_win);
	exit(0);
}
