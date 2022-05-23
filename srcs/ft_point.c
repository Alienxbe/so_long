/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:17:57 by maykman           #+#    #+#             */
/*   Updated: 2022/05/23 21:01:02 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	ft_set_point(int x, int y)
{
	t_point	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

t_point	ft_pos_cmp(t_point p1, t_point p2)
{
	t_point	cmp;

	cmp.x = p2.x - p1.x;
	cmp.y = p2.y - p1.y;
	return (cmp);
}
