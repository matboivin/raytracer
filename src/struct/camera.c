/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:29:07 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/08 18:03:19 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_lstcam		*new_lstcam(t_cam *cam)
{
	t_lstcam	*result;

	result = (t_lstcam *)malloc(sizeof(t_lstcam));
	if (!result)
		return (NULL);
	result->cam = cam;
	result->next = NULL;
	return (result);
}

void			lstcam_append(t_lstcam **cams, t_lstcam *new_cam)
{
	t_lstcam	*cursor;

	if (!cams || !new_cam)
		return ;
	cursor = *cams;
	if (*cams)
	{
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = new_cam;
	}
	else
		*cams = new_cam;
}

void			lstcam_clear(t_lstcam **cams)
{
	t_lstcam	*cursor;
	t_lstcam	*next_node;

	if (!cams)
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
