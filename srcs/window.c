/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 06:09:33 by mykman            #+#    #+#             */
/*   Updated: 2022/05/27 08:29:25 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_win(t_data *d)
{
	d->mlx_ptr = mlx_init();
	if (!d->mlx_ptr)
		ft_error("MLX init failed");
	d->mlx_win = mlx_new_window(d->mlx_ptr, d->win_size.x, d->win_size.y, WIN_NAME);
	if (!d->mlx_win)
		ft_error("MLX win failed");
}
