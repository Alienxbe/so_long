/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:44:40 by maykman           #+#    #+#             */
/*   Updated: 2022/05/24 04:52:21 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	test_map(t_data d, int rot)
{
	mlx_clear_window(d.mlx_ptr, d.mlx_win);
	for (int y = 0; y <= WIN_HEIGHT / TILE_SIZE; y++)
		for (int x = 0; x <= WIN_WIDTH / TILE_SIZE; x++)
			set_tile(d, d.tiles, grass, ft_new_point(x, y));
	for (int i=0; i < 200; i++)
		set_tile(d, d.tiles, i + 128, ft_new_point(2 + i % 8, 2 + i / 8));
	set_tile(d, d.player, 0 + rot * 4, d.pos);
}

int	key_pressed(int key, t_data *d)
{
	ft_printf("Key pressed: %d\n", key);
	if (key == 53)
		exit_game(d);
	if (key == 123)
	{
		d->pos.x--;
		test_map(*d, 1);
	}
	else if (key == 124)
	{
		d->pos.x++;
		test_map(*d, 2);
	}
	else if (key == 125)
	{
		d->pos.y++;
		test_map(*d, 0);
	}
	else if (key == 126)
	{
		d->pos.y--;
		test_map(*d, 3);
	}
	return (0);
}

int	main(void)
{
	t_data	d;

	init_win(&d);
	init_assets(&d);
	ft_printf("%d tiles loaded\n", d.tiles.count);
	d.pos = ft_new_point(1, 1);
	test_map(d, 0);
	mlx_key_hook(d.mlx_win, &key_pressed, &d);
	mlx_loop(d.mlx_ptr);
	exit(0);
}
