/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 00:57:27 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/07 23:09:27 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_lstobj		*new_lstobj(void *obj, t_objid type)
{
	t_lstobj	*result;

	result = malloc(sizeof(t_lstobj));
	if (!result)
		return (NULL);
	result->type = type;
	result->obj = obj;
	result->next = NULL;
	return (result);
}

void			lstobj_append(t_lstobj **objs, t_lstobj *new_obj)
{
	t_lstobj	*cursor;

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

void			lstobj_clear(t_lstobj **objs)
{
	t_lstobj	*cursor;
	t_lstobj	*next_node;

	if (!objs)
		return ;
	cursor = *objs;
	if (*objs)
	{
		while (cursor)
		{
			next_node = cursor->next;
			free(cursor->obj);
			free(cursor);
			cursor = next_node;
		}
		*objs = NULL;
	}
}
