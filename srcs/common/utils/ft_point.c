/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:17:57 by maykman           #+#    #+#             */
/*   Updated: 2022/05/26 15:11:39 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	ft_new_point(int x, int y)
{
	return ((t_point){x, y});
}

t_point	ft_pos_cmp(t_point p1, t_point p2)
{
	return ((t_point){p2.x - p1.x, p2.y - p1.y});
}

void	ft_print_point(t_point p)
{
	ft_printf("x: %d\ty: %d\n", p.x, p.y);
}
