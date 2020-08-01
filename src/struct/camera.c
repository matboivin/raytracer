/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:29:07 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/02 00:05:48 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Camera
**
** new_lstcam()      :  Create a new camera element
** lstcam_add_back() :  Add a new camera at the end of the list
** lstcam_clear()    :  Delete all cameras
*/

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

void			lstcam_clear(t_lstcam **lst)
{
	t_lstcam	*head;
	t_lstcam	*cursor;

	if (lst == NULL)
		return ;
	head = *lst;
	while (*lst)
	{
		cursor = *lst;
		*lst = (*lst)->next;
		free(cursor->cam);
		free(cursor);
		if (*lst == head)
			*lst = NULL;
	}
}
