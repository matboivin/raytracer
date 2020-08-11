/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_to_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:38:29 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/11 18:10:43 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function creates the world_to_cam matrix (World Space to View Space)
**
** Right, Up and Forward vectors
**
** [[Rx, Ry, Rz, T],
**  [Ux, Uy, Uz, T],
**  [Fx, Fy, Fz, T],
**  [ 0,  0,  0, 1]]
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
	result.c1 = create_vec4(right.x, right.y, right.z, from.x);
	result.c2 = create_vec4(up.x, up.y, up.z, from.y);
	result.c3 = create_vec4(forward.x, forward.y, forward.z, from.z);
	result.c4 = create_vec4(0.0, 0.0, 0.0, 1.0);
	return (result);
}

/*
** This function creates the cam_to_world matrix (View Space to World Space)
*/

t_mat4x4		create_camtoworld(t_vec3 from, t_vec3 cam_dir, t_vec3 world_up)
{
	t_mat4x4	result;
	t_mat4x4	world_to_cam;

	world_to_cam = create_worldtocam(from, cam_dir, world_up);
	result = invert_mat4x4(world_to_cam);
	return (result);
}

/*
** This function places the camera and returns the cam_to_world matrix
*/

t_mat4x4		look_at(t_cam *cam)
{
	t_mat4x4	cam_to_world;
	t_vec3		world_up;

	world_up = create_vec3(0.0, 1.0, 0.0);
	cam_to_world = create_camtoworld(cam->pos, cam->dir, world_up);
	return (cam_to_world);
}
