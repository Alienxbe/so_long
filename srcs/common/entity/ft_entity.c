/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:19:15 by mykman            #+#    #+#             */
/*   Updated: 2022/06/16 19:54:40 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_entity	*alloc_entity(t_entity orig)
{
	t_entity	*cpy;

	cpy = (t_entity *)malloc(sizeof(t_entity));
	if (cpy)
		*cpy = orig;
	return (cpy);
}

// void		add_entity(t_list **lst, t_entity *entity)
// {
	
// }
