/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_area.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:28:23 by maykman           #+#    #+#             */
/*   Updated: 2022/05/24 00:12:52 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_area	ft_new_area(int x1, int y1, int x2, int y2)
{
	t_area	area;

	area.p1 = ft_new_point(x1, y1);
	area.p2 = ft_new_point(x2, y2);
	return (area);
}

t_area	ft_point_to_area(t_point p1, t_point p2)
{
	t_area	area;

	area.p1 = p1;
	area.p2 = p2;
	return (area);
}
