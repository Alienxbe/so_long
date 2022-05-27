/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:44:40 by maykman           #+#    #+#             */
/*   Updated: 2022/05/27 15:41:35 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static void	add_animation_frame(t_data *d)
{
	d->game.player.frame++;
	if (d->game.player.frame >= 4 * FRAME_PER_ANIMATION)
		d->game.player.frame = 0;
}

static int	update(t_data *d)
{
	static int		update_count;
	int				active_key_count;
	clock_t			animation_time;
	
	animation_time = clock();
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
	ajust_frame_rate(clock() - animation_time);
	update_count++;
	return (0);
}

int	main(int argc, char **argv) // (filename)
{
	t_data	d;

	if (argc != 2)
		ft_error("Wrong argument count");
	ft_bzero(&d, sizeof(t_data));
	parse_map(&d, argv[1]);
	print_layer(d.map);
	init_win(&d, d.map.size.x, d.map.size.y, WIN_NAME);
	init_assets(&d);
	init_keycode(&d);
	d.game.player.pos = (t_point){1, 1};
	mlx_hook(d.mlx_win, 2, 1L << 0, &key_pressed, &d);
	mlx_hook(d.mlx_win, 3, 1L << 1, &key_released, &d);
	mlx_loop_hook(d.mlx_ptr, &update, &d);
	mlx_loop(d.mlx_ptr);
	exit_game(&d);
}