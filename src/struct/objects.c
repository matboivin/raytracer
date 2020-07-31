/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 00:57:27 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/31 23:16:03 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Objects
**
** new_lstobj()      :  Create a nez object element
** lstobj_add_back() :  Add a new object at the end of the list
** lstobj_clear()    :  Delete all objects
*/

t_lstobj		*new_lstobj(void *obj, char *type)
{
	t_lstobj	*result;

	result = (t_lstobj *)malloc(sizeof(t_lstobj));
	if (result == NULL)
		return (NULL);
	result->type = type;
	result->obj = obj;
	result->next = NULL;
	return (result);
}

void			lstobj_add_back(t_lstobj **lst, t_lstobj *new)
{
	t_lstobj	*cursor;

	if ((lst == NULL) || (new == NULL))
		return ;
	cursor = *lst;
	if (*lst)
	{
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = new;
	}
	else
		*lst = new;
}

void			lstobj_clear(t_lstobj **lst)
{
	t_lstobj	*cursor;
	t_lstobj	*next_node;

	if (lst == NULL)
		return ;
	cursor = *lst;
	if (*lst)
	{
		while (cursor)
		{
			next_node = cursor->next;
			free(cursor->obj);
			free(cursor);
			cursor = next_node;
		}
		*lst = NULL;
	}
}
