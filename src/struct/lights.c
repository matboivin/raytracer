/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:29:07 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/07 18:09:13 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_lstlight		*new_lstlight(t_light *light)
{
	t_lstlight	*result;

	result = (t_lstlight *)malloc(sizeof(t_lstlight));
	if (!result)
		return (NULL);
	result->light = light;
	result->next = NULL;
	return (result);
}

void			lstlight_append(t_lstlight **lst, t_lstlight *new)
{
	t_lstlight	*cursor;

	if (!lst || !new)
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

void			lstlight_clear(t_lstlight **lst)
{
	t_lstlight	*cursor;
	t_lstlight	*next_node;

	if (!lst)
		return ;
	cursor = *lst;
	if (*lst)
	{
		while (cursor)
		{
			next_node = cursor->next;
			free(cursor->light);
			free(cursor);
			cursor = next_node;
		}
		*lst = NULL;
	}
}
