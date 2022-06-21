/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:19:15 by mykman            #+#    #+#             */
/*   Updated: 2022/06/21 20:32:32 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_entity	*entity_new(t_list **entities, t_entity_type type)
{
	t_entity	*entity;
	t_list		*new;

	entity = ft_calloc(1, sizeof(t_entity));
	new = ft_lstnew(entity);
	if (!new || !entity)
	{
		free(entity);
		free(new);
		return (NULL);
	}
	entity->type = type;
	ft_lstadd_back(entities, new);
	return (entity);
}

t_entity	*entity_get_type(t_list *entities, t_entity_type type)
{
	while (entities)
	{
		if (((t_entity *)entities->content)->type == type)
			return ((t_entity *)entities->content);
		entities = entities->next;
	}
	return (NULL);
}

size_t	entity_count_type(t_list *entities, t_entity_type type)
{
	size_t	count;

	count = 0;
	while (entities)
	{
		if (((t_entity *)entities->content)->type == type)
			count++;
		entities = entities->next;
	}
	return (count);
}
