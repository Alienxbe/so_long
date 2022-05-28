/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:53:26 by maykman           #+#    #+#             */
/*   Updated: 2022/05/28 19:19:00 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_pressed(int key, t_data *d)
{
	// ft_printf("Key pressed: %d \n", key);
	for (int i = 0; i < MAX_KEY; i++)
		if (key == d->key[i])
			d->game.key_active[i] = 1;
	return (0);
}

int	key_released(int key, t_data *d)
{
	for (int i = 0; i < MAX_KEY; i++)
		if (key == d->key[i])
			d->game.key_active[i] = 0;
	return (0);
}
