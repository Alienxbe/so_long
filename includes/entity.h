/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:15:38 by mykman            #+#    #+#             */
/*   Updated: 2022/06/20 17:53:22 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

# include "so_long.h"

typedef enum e_entity_type
{
	entity_none,
	entity_player,
	entity_collectible,
	entity_exit
}	t_entity_type;

typedef struct s_entity
{
	t_point			pos;
	int				rot;
	int				frame;
	int				inmove;
	t_asset			sprites;
	t_entity_type	type;
}	t_entity;

t_entity	*entity_new(t_list **entities, t_entity_type type);
t_entity	*entity_get_type(t_list *entities, t_entity_type type);
size_t		entity_count_type(t_list *entities, t_entity_type type);

#endif
