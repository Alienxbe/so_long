/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 13:52:36 by mykman            #+#    #+#             */
/*   Updated: 2022/05/28 13:55:58 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builder.h"

void	key_actions(t_data *d)
{
	if (d->game.key_active[key_esc])
		exit_game(d);
	if (d->game.key_active[key_tab])
		ft_printf("!tab\n");
}
