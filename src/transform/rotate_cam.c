/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:38:29 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/07 16:45:00 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
**    c1    c2      c3
** x [1,     0,     0]
** y [0,  cosx, -sinx]
** z [0,  sinx,  cosx]
*/

static t_mat3x3	cam_rotation_x(double x)
{
	t_mat3x3	result;

	result = identity_mat3x3();
	result.c2.y = cos(x);
	result.c2.z = sin(x);
	result.c3.y = -sin(x);
	result.c3.z = cos(x);
	return (result);
}

/*
**    c1    c2      c3
** x [ cosy, 0,  siny]
** y [    0, 1,     0]
** z [-siny, 0,  cosy]
*/

static t_mat3x3	cam_rotation_y(double y)
{
	t_mat3x3	result;

	result = identity_mat3x3();
	result.c1.x = cos(y);
	result.c1.z = -sin(y);
	result.c3.x = sin(y);
	result.c3.z = cos(y);
	return (result);
}

/*
**    c1       c2   c3
** x [ cosz, -sinz, 0]
** y [ sinz,  cosz, 0]
** z [    0,     0, 1]
*/

static t_mat3x3	cam_rotation_z(double z)
{
	t_mat3x3	result;

	result = identity_mat3x3();
	result.c1.x = cos(z);
	result.c1.y = sin(z);
	result.c2.x = -sin(z);
	result.c2.y = cos(z);
	return (result);
}

t_mat3x3		rotate_cam(t_vec3 coefs)
{
	t_mat3x3	result;
	t_mat3x3	tmp;

	result = cam_rotation_x(coefs.x);
	tmp = cam_rotation_y(coefs.y);
	result = mult_mat3x3_mat3x3(result, tmp);
	tmp = cam_rotation_z(coefs.z);
	result = mult_mat3x3_mat3x3(result, tmp);
	return (result);
}
