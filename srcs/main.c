/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:44:40 by maykman           #+#    #+#             */
/*   Updated: 2022/05/26 23:37:25 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(t_data *d)
{
	// mlx_clear_window(d->mlx_ptr, d->mlx_win);
	for (int y = 0; y <= WIN_HEIGHT / TILE_SIZE; y++)
		for (int x = 0; x <= WIN_WIDTH / TILE_SIZE; x++)
			set_tile(*d, d->assets.tiles, grass, (t_point){x, y});
	// for (int i=0; i < 400; i++)
	// 	set_tile(*d, d->assets.tiles, i, (t_point){i % 8, i / 8});
	// for (int i = 0; i < 16; i++)
	// 	set_tile(*d, d->assets.tiles, grass_pkmn, ft_new_point(5 + i % 4, 5 + i / 4));
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
	ft_printf("fps: %d\n", d->game.fps);
	update_count++;
	return (0);
}

int	main(void)
{
	t_data	d;

	ft_bzero(&d, sizeof(t_data));
	init_win(&d);
	init_assets(&d);
	init_keycode(&d);
	parse_map(&d, "maps/map_bonus.ber");
	d.game.player.pos = (t_point){5, 5};
	mlx_hook(d.mlx_win, 2, 1L << 0, &key_pressed, &d);
	mlx_hook(d.mlx_win, 3, 1L << 1, &key_released, &d);
	mlx_loop_hook(d.mlx_ptr, &update, &d);
	mlx_loop(d.mlx_ptr);
	exit(0);
}
