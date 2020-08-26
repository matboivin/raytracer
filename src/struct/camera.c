/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:29:07 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/27 00:23:02 by mboivin          ###   ########.fr       */
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

void			lstcam_add_back(t_lstcam **cams, t_lstcam *new)
{
	t_lstcam	*cursor;

	if ((cams == NULL) || (new == NULL))
		return ;
	cursor = *cams;
	if (*cams)
	{
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = new;
	}
	else
		*cams = new;
}

void			lstcam_clear(t_lstcam **cams)
{
	t_lstcam	*cursor;
	t_lstcam	*next_node;

	if (cams == NULL)
		return ;
	cursor = *cams;
	if (*cams)
	{
		while (cursor)
		{
			next_node = cursor->next;
			free(cursor->cam);
			free(cursor);
			cursor = next_node;
		}
		*cams = NULL;
	}
}
