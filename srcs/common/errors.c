/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 06:13:02 by mykman            #+#    #+#             */
/*   Updated: 2022/06/20 16:13:29 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ft_error(const char *error_msg)
{
	ft_fprintf(STDERR_FILENO, "Error : %s\n", error_msg);
	exit(1);
}

void	free_layer(t_layer layer, t_point size)
{
	int	y;

	y = -1;
	while (++y < size.y)
		free(layer[y]);
	free(layer);
}

void	exit_game(t_data *d)
{
	int	i;

	i = -1;
	while (++i < d->map.layer_count)
		free_layer(d->map.layers[i], d->map.size);
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
	ft_lstclear(&d->entities, &free);
	if (d->mlx_ptr && d->mlx_win)
		mlx_destroy_window(d->mlx_ptr, d->mlx_win);
	ft_printf("Everything was freed without issues\n");
	exit(0);
}
