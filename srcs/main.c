/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:44:40 by maykman           #+#    #+#             */
/*   Updated: 2022/05/24 08:02:00 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	test_map(t_data *d)
{
	mlx_clear_window(d->mlx_ptr, d->mlx_win);
	for (int y = 0; y <= WIN_HEIGHT / TILE_SIZE; y++)
		for (int x = 0; x <= WIN_WIDTH / TILE_SIZE; x++)
			set_tile(*d, d->assets.tiles, grass, ft_new_point(x, y));
	for (int i=0; i < 200; i++)
		set_tile(*d, d->assets.tiles, i, ft_new_point(i % 8, i / 8));
	set_tile(*d, d->assets.player, d->game.player.frame + d->game.player.rot * 4, d->game.player.pos);
	return (0);
}

void	init_keycode(t_data *d)
{
	if (ft_strncmp(OS, "Linux", ft_strlen(OS)))
	{
		d->key[key_up] = 126;
		d->key[key_down] = 125;
		d->key[key_left] = 123;
		d->key[key_right] = 124;
		d->key[key_esc] = 53;
	}
	else if (ft_strncmp(OS, "Darwin", ft_strlen(OS)))
	{
		d->key[key_up] = 65362;
		d->key[key_down] = 65364;
		d->key[key_left] = 65361;
		d->key[key_right] = 65363;
		d->key[key_esc] = 65307;
	}
	else
		ft_error("Wrong OS detected");
}

int	key_pressed(int key, t_data *d)
{
	ft_printf("Key pressed: %d (%d, %d)\n", key, d->game.player.pos.x, d->game.player.pos.y);
	if (key == d->key[key_esc])
		exit_game(d);
	if (key == d->key[key_left])
	{
		d->game.player.pos.x--;
		d->game.player.rot = 1;
	}
	else if (key == d->key[key_right])
	{
		d->game.player.pos.x++;
		d->game.player.rot = 2;
	}
	else if (key == d->key[key_down])
	{
		d->game.player.pos.y++;
		d->game.player.rot = 0;
	}
	else if (key == d->key[key_up])
	{
		d->game.player.pos.y--;
		d->game.player.rot = 3;
	}
	d->game.player.frame++;
	if (d->game.player.frame == 4)
		d->game.player.frame = 0;
	test_map(d);
	return (0);
}

int	main(void)
{
	t_data	d;

	ft_bzero(&d, sizeof(t_data));
	init_win(&d);
	init_assets(&d);
	init_keycode(&d);
	test_map(&d);
	mlx_hook(d.mlx_win, 2, 1L << 0, &key_pressed, &d);
	mlx_loop(d.mlx_ptr);
	exit(0);
}
