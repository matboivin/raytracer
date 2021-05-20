/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 00:57:27 by mboivin           #+#    #+#             */
/*   Updated: 2021/05/20 15:07:04 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj		*create_obj(void *shape_data, t_objid shape_id)
{
	t_obj	*result = NULL;

	result = malloc(sizeof(t_obj));
	if (!result)
		return (NULL);
	result->id = shape_id;
	result->data = shape_data;
	result->next = NULL;
	return (result);
}

void		append_obj(t_obj **objs, t_obj *new_obj)
{
	t_obj	*cursor = NULL;

	if (!objs || !new_obj)
		return ;
	cursor = *objs;
	if (*objs)
	{
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = new_obj;
	}
	else
		*objs = new_obj;
}

void		delete_objs(t_obj **objs)
{
	t_obj	*cursor = NULL;
	t_obj	*next_node = NULL;

	if (!objs)
		return ;
	cursor = *objs;
	if (*objs)
	{
		while (cursor)
		{
			next_node = cursor->next;
			free(cursor->data);
			free(cursor);
			cursor = next_node;
		}
		*objs = NULL;
	}
}
