/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_to_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:38:29 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/12 00:42:51 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function creates the world_to_cam matrix (World Space to View Space)
**
** Right, Up and Forward vectors
**
** [Rx, Ux, Fx, Tx]
** [Ry, Uy, Fy, Ty]
** [Rz, Uz, Fz, Tz]
** [0., 0., 0., 1.]
*/

t_mat4x4		create_worldtocam(t_vec3 from, t_vec3 cam_dir, t_vec3 world_up)
{
	t_mat4x4	result;
	t_vec3		forward;
	t_vec3		up;
	t_vec3		right;

	forward = cam_dir;
	right = normalize_vec3(cross(world_up, forward));
	up = normalize_vec3(cross(forward, right));
	forward = normalize_vec3(forward);
	result.c1 = create_vec4(right.x, right.y, right.z, 0.0);
	result.c2 = create_vec4(up.x, up.y, up.z, 0.0);
	result.c3 = create_vec4(forward.x, forward.y, forward.z, 0.0);
	result.c4 = create_vec4(from.x, from.y, from.z, 1.0);
	return (result);
}

/*
** This function creates the cam_to_world 4D matrix (View Space to World Space)
*/

t_mat4x4		create_camtoworld4(t_vec3 from, t_vec3 cam_dir, t_vec3 world_up)
{
	t_mat4x4	result;
	t_mat4x4	world_to_cam;

	world_to_cam = create_worldtocam(from, cam_dir, world_up);
	result = invert_mat4x4(world_to_cam);
	return (result);
}

/*
** This function creates the cam_to_world 3D matrix (View Space to World Space)
*/

t_mat3x3		create_camtoworld3(t_mat4x4 mat)
{
	t_mat3x3	result;

	result.c1 = create_vec3(mat.c1.x, mat.c1.y, mat.c1.z);
	result.c2 = create_vec3(mat.c2.x, mat.c2.y, mat.c2.z);
	result.c3 = create_vec3(mat.c3.x, mat.c3.y, mat.c3.z);
	return (result);
}

/*
** This function places the camera and returns the cam_to_world matrix
*/

void			look_at(t_cam *cam)
{
	t_vec3		world_up;

	world_up = create_vec3(0.0, 1.0, 0.0);
	cam->cam_to_world4 = create_camtoworld4(cam->pos, cam->dir, world_up);
	cam->cam_to_world3 = create_camtoworld3(cam->cam_to_world4);
}
