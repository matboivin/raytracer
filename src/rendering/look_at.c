/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_at.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:38:29 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/13 01:26:14 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function creates the World Space to Camera Space 3D matrix
**
** Right, Up and Forward vectors
**
** [Rx, Ux, Fx]
** [Ry, Uy, Fy]
** [Rz, Uz, Fz]
*/

static void		check_collinear_vectors(
	t_vec3 cam_dir, t_vec3 *right, t_vec3 world_up)
{
	if (cam_dir.y == UNIT_VALUE)
		*right = create_vec3(UNIT_VALUE, DEFAULT_VALUE, DEFAULT_VALUE);
	else if (cam_dir.y == REVUNIT_VALUE)
		*right = create_vec3(REVUNIT_VALUE, DEFAULT_VALUE, DEFAULT_VALUE);
	else
		*right = cross(normalize_vec3(world_up), cam_dir);
}

static t_mat3x3	create_worldtocam(t_vec3 cam_dir, t_vec3 world_up)
{
	t_mat3x3	result;
	t_vec3		forward;
	t_vec3		up;
	t_vec3		right;

	forward = cam_dir;
	check_collinear_vectors(cam_dir, &right, world_up);
	up = cross(forward, right);
	result.c1 = create_vec3(right.x, right.y, right.z);
	result.c2 = create_vec3(up.x, up.y, up.z);
	result.c3 = create_vec3(forward.x, forward.y, forward.z);
	return (result);
}

/*
** This function creates the Camera Space to World Space 3D matrix
*/

static t_mat3x3	create_camtoworld(t_vec3 cam_dir, t_vec3 world_up)
{
	t_mat3x3	result;
	t_mat3x3	world_to_cam;

	world_to_cam = create_worldtocam(cam_dir, world_up);
	result = invert_mat3x3(world_to_cam);
	return (result);
}

/*
** This function places the camera and sets Camera Space to World Space matrices
*/

void			look_at(t_cam *cam)
{
	t_vec3		world_up;

	world_up = create_vec3(DEFAULT_VALUE, UNIT_VALUE, DEFAULT_VALUE);
	cam->cam_to_world = create_camtoworld(cam->dir, world_up);
}
