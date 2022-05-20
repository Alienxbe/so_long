/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:17:57 by maykman           #+#    #+#             */
/*   Updated: 2022/05/20 23:24:27 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos	ft_new_pos(int x, int y)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

t_pos	ft_pos_cmp(t_pos p1, t_pos p2)
{
	t_pos	cmp;

	cmp.x = p2.x - p1.x;
	cmp.y = p2.y - p1.y;
	return (cmp);
}
