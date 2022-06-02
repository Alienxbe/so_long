/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 06:09:33 by mykman            #+#    #+#             */
/*   Updated: 2022/06/02 21:28:54 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	init_win(t_data *d, int width, int height, char *name)
{
	d->mlx_ptr = mlx_init();
	if (!d->mlx_ptr)
		ft_error("MLX init failed");
	d->mlx_win = mlx_new_window(d->mlx_ptr, width * d->map.tile_size,
		height * d->map.tile_size, name);
	if (!d->mlx_win)
		ft_error("MLX win failed");
}

void	init_keycode(t_data *d)
{
	if (!ft_strncmp(OS, "Linux", ft_strlen(OS)))
	{
		d->key[key_up] = 65362;
		d->key[key_down] = 65364;
		d->key[key_left] = 65361;
		d->key[key_right] = 65363;
		d->key[key_esc] = 65307;
		d->key[key_tab] = 65289;
	}
	else if (!ft_strncmp(OS, "Darwin", ft_strlen(OS)))
	{
		d->key[key_up] = 126;
		d->key[key_down] = 125;
		d->key[key_left] = 123;
		d->key[key_right] = 124;
		d->key[key_esc] = 53;
		d->key[key_tab] = 48;
	}
	else
		ft_error("Wrong OS detected");
}
