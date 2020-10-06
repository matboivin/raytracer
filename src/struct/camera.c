/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:29:07 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/06 23:26:07 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cameras		*create_cam(t_cam *cam)
{
	t_cameras	*result;

	result = (t_cameras *)malloc(sizeof(t_cameras));
	if (!result)
		return (NULL);
	result->cam = cam;
	result->next = NULL;
	return (result);
}

void			append_camera(t_cameras **cams, t_cameras *new_cam)
{
	t_cameras	*cursor;

	if (!cams || !new_cam)
		return ;
	if (*cams)
	{
		cursor = *cams;
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = new_cam;
	}
	else
		*cams = new_cam;
}

void			delete_cameras(t_cameras **cams)
{
	t_cameras	*cursor;
	t_cameras	*next_node;

	if (!cams)
		return ;
	if (*cams)
	{
		cursor = *cams;
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
