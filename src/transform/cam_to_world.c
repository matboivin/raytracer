/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_to_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:38:29 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/05 18:01:45 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 4x4 Matrix: cam_to_world
**
** LookAt, Up and Right vectors
**
** [[1, 0, 0, 0],  [[R, R, R, 0],
**  [0, 1, 0, 0],   [U, U, U, 0],
**  [0, 0, 1, 0],   [A, A, A, 0],
**  [0, 0, 0, 1]]   [T, T, T, 1]]
*/

t_mat4x4		create_camtoworld(t_vec3 from, t_vec3 to, t_vec3 world_up)
{
	t_mat4x4	result;
	t_vec3		look_at;
	t_vec3		up;
	t_vec3		right;

	look_at = normalize_vec3(sub_vec3(from, to));
	right = normalize_vec3(cross(world_up, look_at));
	up = cross(look_at, right);
	result.c1 = create_vec4(right.x, right.y, right.z, from.x);
	result.c2 = create_vec4(up.x, up.y, up.z, from.y);
	result.c3 = create_vec4(look_at.x, look_at.y, look_at.z, from.z);
	result.c4 = create_vec4(0, 0, 0, 1);
	return (result);
}

t_mat4x4		look_at(t_cam *cam)
{
	t_mat4x4	cam_to_world;
	t_vec3		world_center;
	t_vec3		world_up;

	world_center = create_vec3(0, 0, 0);
	world_up = create_vec3(0, 1, 0);
	cam_to_world = create_camtoworld(cam->pos, world_center, world_up);
	return (cam_to_world);
}
