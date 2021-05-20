/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:29:07 by mboivin           #+#    #+#             */
/*   Updated: 2021/05/20 15:06:33 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include "minirt.h"

t_camera		*malloc_cam(t_minirt *env)
{
	t_camera	*result = NULL;

	result = malloc(sizeof(t_camera));
	if (!result)
		exit_error(env, (char *)strerror(errno));
	result->pos = create_vec3(DEFAULT_VALUE, DEFAULT_VALUE, DEFAULT_VALUE);
	result->dir = create_vec3(DEFAULT_VALUE, DEFAULT_VALUE, DEFAULT_VALUE);
	result->fov = DEFAULT_VALUE;
	result->cam_to_world = identity_mat3x3();
	result->next = NULL;
	return (result);
}

void			append_camera(t_camera **cams, t_camera *new_cam)
{
	t_camera	*cursor = NULL;

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

void			delete_cameras(t_camera **cams)
{
	t_camera	*cursor = NULL;
	t_camera	*next_node = NULL;

	if (!cams)
		return ;
	if (*cams)
	{
		cursor = *cams;
		while (cursor)
		{
			next_node = cursor->next;
			free(cursor);
			cursor = next_node;
		}
		*cams = NULL;
	}
}
