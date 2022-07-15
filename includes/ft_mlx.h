/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:15:19 by mykman            #+#    #+#             */
/*   Updated: 2022/06/24 23:20:28 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

# include "common.h"

// Better pixel_put
void	ft_pixel_put(t_mlx_img *img, int x, int y, unsigned int color);

#endif
