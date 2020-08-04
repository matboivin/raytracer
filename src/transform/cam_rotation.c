/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:38:29 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/04 21:22:57 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			cam_rotation_x(t_mat4x4 *mat, double x)
{
	mat->c2.y = cos(x);
	mat->c2.z = -sin(x);
	mat->c3.y = sin(x);
	mat->c3.z = cos(x);
}

void			cam_rotation_y(t_mat4x4 *mat, double y)
{
	mat->c1.x = cos(y);
	mat->c1.z = sin(y);
	mat->c3.x = -sin(y);
	mat->c3.z = cos(y);
}

void			cam_rotation_z(t_mat4x4 *mat, double z)
{
	mat->c1.x = cos(z);
	mat->c2.y = -sin(z);
	mat->c2.x = sin(z);
	mat->c2.y = cos(z);
}

t_mat4x4		rotate_cam(t_vec3 dir)
{
	t_mat4x4	result;

	result = identity_mat4x4();
	cam_rotation_x(&result, dir.x);
	cam_rotation_y(&result, dir.y);
	cam_rotation_z(&result, dir.z);
	return (result);
}
