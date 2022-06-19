/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:19:15 by mykman            #+#    #+#             */
/*   Updated: 2022/06/19 03:59:48 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	new_entity(t_list **entities)
{
	static int	id_count;
	t_entity	*entity;
	t_list		*new;

	entity = ft_calloc(1, sizeof(t_entity));
	new = ft_lstnew(entity);
	if (!new || !entity)
	{
		free(entity);
		return (-1);
	}
	entity->id = id_count;
	ft_lstadd_back(entities, new);
	return (id_count++);
}

t_entity	*get_entity(t_list *entities, int id)
{
	while (entities && ((t_entity *)entities->content)->id != id)
	{
		ft_printf("%d\n", id);
		entities = entities->next;
	}
	ft_printf("Exit loop\n");
	if (!entities)
		return (NULL);
	return ((t_entity *)entities->content);
}



