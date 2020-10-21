/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:29:07 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/21 15:05:47 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera		*malloc_cam(t_minirt *env)
{
	t_camera	*result;

	result = malloc(sizeof(t_camera));
	if (!result)
		exit_error(env, ERRNO_TO_STR);
	result->pos = create_vec3(DEFAULT_VALUE, DEFAULT_VALUE, DEFAULT_VALUE);
	result->dir = create_vec3(DEFAULT_VALUE, DEFAULT_VALUE, DEFAULT_VALUE);
	result->fov = DEFAULT_VALUE;
	result->cam_to_world = identity_mat3x3();
	result->next = NULL;
	return (result);
}

void			append_camera(t_camera **cams, t_camera *new_cam)
{
	t_camera	*cursor;

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
	t_camera	*cursor;
	t_camera	*next_node;

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
