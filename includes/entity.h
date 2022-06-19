/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:15:38 by mykman            #+#    #+#             */
/*   Updated: 2022/06/19 03:46:15 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

# include "so_long.h"

typedef struct s_entity
{
	t_point	pos;
	char	*name;
	int		rot;
	int		frame;
	int		inmove;
	int		id;
}	t_entity;

int			new_entity(t_list **entities);
t_entity	*get_entity(t_list *entities, int id);

#endif
