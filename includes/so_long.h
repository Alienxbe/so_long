/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 23:54:20 by mykman            #+#    #+#             */
/*   Updated: 2022/05/20 07:26:03 by mykman           ###   ########.fr       */
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
t_img	new_asset(void *mlx_ptr, char *filename);
void	init_assets(t_data *d);

// Window
void	init_win(t_data *d);

// Map
void	set_tile(t_data d, t_img img, int x, int y);

// Errors
void	ft_error(const char *error_msg);

#endif
