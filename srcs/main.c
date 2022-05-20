/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:44:40 by maykman           #+#    #+#             */
/*   Updated: 2022/05/20 20:40:05 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	new_asset(void *mlx_ptr, char *filename);

void	ft_error(const char *error_msg)
{
	ft_fprintf(STDERR_FILENO, "Error : %s\n", error_msg);
	exit(1);
}

void	init_win(t_data *d)
{
	d->mlx_ptr = mlx_init();
	if (!d->mlx_ptr)
		ft_error("MLX init failed");
	d->mlx_win = mlx_new_window(d->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	if (!d->mlx_win)
		ft_error("MLX win failed");
}

void	init_assets(t_data *d)
{
	ft_bzero(d->assets, sizeof(t_img) * assets_count);
	d->assets[grass] = new_asset(d->mlx_ptr, XPM_FOLDER"grass.xpm");
	d->assets[grassy_grass] = new_asset(d->mlx_ptr, XPM_FOLDER"grassy_grass.xpm");
	d->assets[flower1_grass] = new_asset(d->mlx_ptr, XPM_FOLDER"flower1_grass.xpm");
	d->assets[flower2_grass] = new_asset(d->mlx_ptr, XPM_FOLDER"flower2_grass.xpm");
	d->assets[pkmn_grass] = new_asset(d->mlx_ptr, XPM_FOLDER"pkmn_grass.xpm");
	d->assets[sign] = new_asset(d->mlx_ptr, XPM_FOLDER"sign.xpm");
	d->assets[red] = new_asset(d->mlx_ptr, XPM_FOLDER"red.xpm");
}

t_img	new_asset(void *mlx_ptr, char *filename)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx_ptr, filename, &img.width, &img.height);
	return (img);
}

void	set_tile(t_data d, t_img img, int x, int y)
{
	x = x * TILE_SIZE + TILE_SIZE - img.width;
	y = y * TILE_SIZE + TILE_SIZE - img.height;
	mlx_put_image_to_window(d.mlx_ptr, d.mlx_win, img.img, x, y);
}

void	test_map(t_data d)
{
	for (int y = 0; y <= WIN_HEIGHT / TILE_SIZE; y++)
	{
		for (int x = 0; x <= WIN_WIDTH / TILE_SIZE; x++)
		{
				if (!((x * y) % 15))
					set_tile(d, d.assets[grassy_grass], x, y);
				else if (!((x * y) % 20))
					set_tile(d, d.assets[pkmn_grass],x, y);
				else if (((x * y) % 15) == 2)
					set_tile(d, d.assets[flower1_grass], x, y);
				else if (((x * y) % 20) == 2)
					set_tile(d, d.assets[flower2_grass], x, y);
				else
					set_tile(d, d.assets[grass], x, y);
		}
	}
	for (int y = 0; y < 3; y++)
		for (int x = 0; x < 3; x++)
			set_tile(d, d.assets[pkmn_grass], x + 7, y + 5);
	set_tile(d, d.assets[sign], 10, 6);
	set_tile(d, d.assets[red], 11, 7);
}

int	main(void)
{
	t_data	d;

	init_win(&d);
	init_assets(&d);
	test_map(d);
	mlx_loop(d.mlx_ptr);
	mlx_destroy_window(d.mlx_ptr, d.mlx_win);
	for (int i = 0; i < assets_count; i++)
		if (d.assets[i].img)
			mlx_destroy_image(d.mlx_ptr, d.assets[i].img);
	exit(0);
}
