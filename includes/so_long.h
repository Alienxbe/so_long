/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 23:54:20 by mykman            #+#    #+#             */
/*   Updated: 2022/05/23 23:07:38 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>

# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "structures.h"

# define WIN_WIDTH	750
# define WIN_HEIGHT	500
# define WIN_NAME	"so_long"

# define ASSETS_FOLDER	"assets/"
# define XPM_FOLDER		"assets/xpm/"
# define TILE_SIZE		32

/*
** Functions
*/

// Assets
void			init_assets(t_data *d);

// Window
void			init_win(t_data *d);

// Map
void			set_tile(t_data d, t_img img, int x, int y);

// Errors
void			ft_error(const char *error_msg);

/*
** Utils functions
*/

// MLX custom functions
void			ft_pixel_put(t_mlx_img *img, int x, int y, unsigned int color);
unsigned int	ft_get_pixel_color(t_mlx_img *img, int x, int y);
t_mlx_img		ft_img_to_mlx_img(void	*img);
t_img			ft_xpm_file_to_img(void *mlx_ptr, char *filename);
t_img			ft_new_subimage(void *mlx_ptr, t_img img, t_area area);

// Points
t_point			ft_new_point(int x, int y);
t_point			ft_pos_cmp(t_point p1, t_point p2);

// Areas
t_area			ft_new_area(t_point p1, t_point p2);

#endif
