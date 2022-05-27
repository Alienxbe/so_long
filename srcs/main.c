/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:44:40 by maykman           #+#    #+#             */
/*   Updated: 2022/05/27 08:59:40 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(t_data *d)
{
	mlx_clear_window(d->mlx_ptr, d->mlx_win);
	for (int y = 0; y < d->map.size.y; y++)
		for (int x = 0; x <= d->map.size.x; x++)
			set_tile(*d, d->assets.tiles, grass, (t_point){x, y});
	// for (int i=0; i < 200; i++)
	// 	set_tile(*d, d->assets.tiles, i + 100, (t_point){i % 8, i / 8});
	// for (int i = 0; i < 16; i++)
	// 	set_tile(*d, d->assets.tiles, grass_pkmn, ft_new_point(5 + i % 4, 5 + i / 4));
	for (int y = 0; y < d->map.size.y; y++)
		for (int x = 0; x < d->map.size.x; x++)
		{
			if (d->map.layers[0][y][x] == 1)
				d->map.layers[0][y][x] = 141;
			if (d->map.layers[0][y][x] == 2)
				d->map.layers[0][y][x] = 143;
			if (d->map.layers[0][y][x] == 5)
				d->map.layers[0][y][x] = 137;
			if (d->map.layers[0][y][x] == 6)
				d->map.layers[0][y][x] = 139;
			if (d->map.layers[0][y][x] == 7)
				d->map.layers[0][y][x] = 153;
			if (d->map.layers[0][y][x] == 8)
				d->map.layers[0][y][x] = 155;
			set_tile(*d, d->assets.tiles, d->map.layers[0][y][x], (t_point){x, y});
		}
	for (int i = 0; i < 4; i++)
		set_tile(*d, d->assets.tiles, 146, (t_point){1 + i, 4});
	// rendering player
	set_tile(*d, d->assets.player, d->game.player.frame / (FRAME_PER_ANIMATION) + d->game.player.rot * 4, d->game.player.pos);
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
	}
	else if (!ft_strncmp(OS, "Darwin", ft_strlen(OS)))
	{
		d->key[key_up] = 126;
		d->key[key_down] = 125;
		d->key[key_left] = 123;
		d->key[key_right] = 124;
		d->key[key_esc] = 53;
	}
	else
		ft_error("Wrong OS detected");
}

int	key_pressed(int key, t_data *d)
{
	// ft_printf("Key pressed: %d (%d, %d)\n", key, d->game.player.pos.x, d->game.player.pos.y);
	for (int i = 0; i < MAX_KEY; i++)
		if (key == d->key[i])
			d->game.key_active[i] = 1;
	return (0);
}

int	key_released(int key, t_data *d)
{
	for (int i = 0; i < MAX_KEY; i++)
		if (key == d->key[i])
			d->game.key_active[i] = 0;
	return (0);
}

static void	add_animation_frame(t_data *d)
{
	d->game.player.frame++;
	if (d->game.player.frame >= 4 * FRAME_PER_ANIMATION)
		d->game.player.frame = 0;
}

int	update(t_data *d)
{
	static int		update_count;
	int				active_key_count;
	clock_t			fps;
	
	fps = clock();
	if (d->game.key_active[key_esc])
		exit_game(d);
	active_key_count = 0;
	if (d->game.player.frame == 0 || d->game.player.frame == 2 * FRAME_PER_ANIMATION)
	{
		for (int i = 0; i <= key_up; i++)
		{
			if (d->game.key_active[i])
			{
				active_key_count++;
				d->game.player.rot = i;
				add_animation_frame(d);
				break;
			}
		}
	}
	else
		add_animation_frame(d);
	draw(d); // Tick / frame
	fps = clock() - fps;
	if (fps < (CLOCKS_PER_SEC / FPS_MAX))
	{
		usleep((CLOCKS_PER_SEC / FPS_MAX) - fps);
		fps = (CLOCKS_PER_SEC / FPS_MAX);
	}
	d->game.fps = CLOCKS_PER_SEC / fps;
	if (SHOW_FPS)
		ft_printf("fps: %d\n", d->game.fps);
	update_count++;
	return (0);
}

static void	print_layer(t_map map)
{
	t_layer layer;

	layer = map.layers[0];
	for (int y = 0; y < map.size.y; y++)
	{
		for (int x = 0; x < map.size.x; x++)
			ft_printf("%d ", layer[y][x]);
		ft_printf("\n");
	}
}

int	main(int argc, char **argv)
{
	t_data	d;

	if (argc != 2)
		ft_error("Wrong argument count");
	ft_bzero(&d, sizeof(t_data));
	parse_map(&d, argv[1]);
	print_layer(d.map);
	init_win(&d);
	init_assets(&d);
	init_keycode(&d);
	d.game.player.pos = (t_point){d.map.size.x / 2, d.map.size.y / 2};
	mlx_hook(d.mlx_win, 2, 1L << 0, &key_pressed, &d);
	mlx_hook(d.mlx_win, 3, 1L << 1, &key_released, &d);
	mlx_loop_hook(d.mlx_ptr, &update, &d);
	mlx_loop(d.mlx_ptr);
	exit(0);
}
