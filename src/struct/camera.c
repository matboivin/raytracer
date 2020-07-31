/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:29:07 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/31 16:25:46 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_lstcam		*new_lstcam(t_cam *cam)
{
	t_lstcam	*result;

	result = (t_lstcam *)malloc(sizeof(t_lstcam));
	if (result == NULL)
		return (NULL);
	result->cam = cam;
	result->next = NULL;
	return (result);
}

void			lstcam_add_back(t_lstcam **lst, t_lstcam *new)
{
	t_lstcam	*cursor;

	if (lst == NULL || new == NULL)
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

void			lstcam_clear(t_lstcam **lst)
{
	t_lstcam	*cursor;
	t_lstcam	*next_node;

	if (lst == NULL)
		return ;
	cursor = *lst;
	if (*lst)
	{
		while (cursor)
		{
			next_node = cursor->next;
			free(cursor->cam);
			free(cursor);
			cursor = next_node;
		}
		*lst = NULL;
	}
}
