/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 13:52:36 by mykman            #+#    #+#             */
/*   Updated: 2022/05/29 00:05:30 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builder.h"

int	detect_key_state(t_data *d, int key)
{
	static int	key_in_use[MAX_KEY];
	static int	key_state[MAX_KEY];

	if (d->game.key_active[key] && !key_in_use[key])
	{
		key_in_use[key] = 1;
		if (!key_state[key])
			key_state[key] = 1;
		else
			key_state[key] = 0;
	}
	else if (!d->game.key_active[key_tab] && key_in_use[key])
		key_in_use[key] = 0;
	return (key_state[key]);
}

void	key_actions(t_data *d)
{
	if (d->game.key_active[key_esc])
		exit_game(d);
	d->game.ismenu = detect_key_state(d, key_tab);
}
