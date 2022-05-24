/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:29:31 by mykman            #+#    #+#             */
/*   Updated: 2022/05/24 04:01:35 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	copy_subimg(t_mlx_img *sub_mlx_img, t_mlx_img *mlx_img,
	t_point size, t_point p1)
{
	int	x;
	int	y;

	y = -1;
	while (++y < size.y)
	{
		x = -1;
		while (++x < size.x)
		{
			ft_pixel_put(sub_mlx_img, x, y,
				ft_get_pixel_color(mlx_img, p1.x + x, p1.y + y));
		}
	}
}

void	ft_pixel_put(t_mlx_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	ft_get_pixel_color(t_mlx_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	return (*(unsigned int *)dst);
}

t_mlx_img	ft_img_to_mlx_img(void	*img)
{
	t_mlx_img	mlx_img;

	ft_bzero(&mlx_img, sizeof(t_mlx_img));
	if (!img)
		return (mlx_img);
	mlx_img.img = img;
	mlx_img.addr = mlx_get_data_addr(mlx_img.img, &mlx_img.bpp,
			&mlx_img.line_length, &mlx_img.endian);
	return (mlx_img);
}

t_img	ft_new_subimage(void *mlx_ptr, t_img img, t_area area)
{
	t_mlx_img	mlx_img;
	t_mlx_img	sub_mlx_img;
	t_img		sub_img;
	t_point		size;

	ft_bzero(&sub_img, sizeof(t_img));
	size = ft_pos_cmp(area.p1, area.p2);
	if (size.x < 0 || size.y < 0
		|| area.p1.x < 0 || area.p1.y < 0
		|| area.p2.x > img.size.x || area.p2.y > img.size.y)
		return (sub_img);
	mlx_img = ft_img_to_mlx_img(img.img);
	sub_mlx_img = ft_img_to_mlx_img(mlx_new_image(mlx_ptr, size.x, size.y));
	if (!sub_mlx_img.img)
		return (sub_img);
	copy_subimg(&sub_mlx_img, &mlx_img, size, area.p1);
	sub_img.img = sub_mlx_img.img;
	sub_img.size.x = size.x;
	sub_img.size.y = size.y;
	return (sub_img);
}
