/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 00:00:48 by mykman            #+#    #+#             */
/*   Updated: 2022/05/18 02:03:29 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_game
{
	int	color;
}	t_game;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	img;
	t_game	game;
}	t_data;


#define WIN_WIDTH	750
#define WIN_HEIGHT	500
#define WIN_NAME	"so_long"

void	ft_pixel_put(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 && x > WIN_WIDTH && y < 0 && y > WIN_HEIGHT)
		return ;
	dst = img.addr + (y * img.line_length + x * (img.bpp / 8));
	*(unsigned int*)dst = color;
}

int	to_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return (r << 16 | g << 8 | b);
}

int	close_win(t_data *d)
{
	mlx_destroy_image(d->mlx_ptr, d->img.img);
	mlx_destroy_window(d->mlx_ptr, d->mlx_win);
	exit(0);
}

int	key_pressed(int keycode, t_data *d)
{
	ft_printf("+ Key pressed! (%3d)\n", keycode);
	if (keycode == 53)
		return (close_win(d));
	return (0);
}

int	key_released(int keycode, t_data *d)
{
	ft_printf("- Key released! (%3d)\n", keycode);
	(void)d;
	return (0);
}

void	set_background(t_data *d, int color)
{
	// Create image
	d->img.img = mlx_new_image(d->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!d->img.img)
		exit(0);
	d->img.addr = mlx_get_data_addr(d->img.img, &d->img.bpp, &d->img.line_length,
								&d->img.endian);
	d->game.color = color;
	for (int y = 0; y < WIN_HEIGHT; y++)
		for (int x = 0; x < WIN_WIDTH; x++)
			ft_pixel_put(d->img, x, y, d->game.color);
	// Set image to the window
	mlx_put_image_to_window(d->mlx_ptr, d->mlx_win, d->img.img, 0, 0);
}

int	main(void)
{
	t_data	d;
	t_img	xpm;

	d.mlx_ptr = mlx_init();
	if (!d.mlx_ptr)
		exit(0);
	d.mlx_win = mlx_new_window(d.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	if (!d.mlx_win)
		exit(0);

	set_background(&d, to_rgb(-1, 0, 0));

	xpm.img = mlx_xpm_file_to_image(d.mlx_ptr, "assets/testimg.xpm", &xpm.width, &xpm.height);
	mlx_put_image_to_window(d.mlx_ptr, d.mlx_win, xpm.img, 0, 0);
	mlx_destroy_image(d.mlx_ptr, xpm.img);

	// Events
	mlx_hook(d.mlx_win, 2, 1L << 0, &key_pressed, &d);
	mlx_hook(d.mlx_win, 3, 1L << 1, &key_released, &d);
	mlx_loop(d.mlx_ptr);
	// Destroy
	mlx_destroy_image(d.mlx_ptr, d.img.img);
	mlx_destroy_window(d.mlx_ptr, d.mlx_win);
	exit(0);
}
