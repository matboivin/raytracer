/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:38:29 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/04 17:26:50 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
**    c1    c2      c3
** x [1,     0,     0]
** y [0,  cosx, -sinx]
** z [0,  sinx,  cosx]
*/

static void		cam_rotation_x(t_mat3x3 *mat, double x)
{
	mat->c2.y = cos(x);
	mat->c2.z = sin(x);
	mat->c3.y = -sin(x);
	mat->c3.z = cos(x);
}

/*
**    c1    c2      c3
** x [ cosy, 0,  siny]
** y [    0, 1,     0]
** z [-siny, 0,  cosy]
*/

static void		cam_rotation_y(t_mat3x3 *mat, double y)
{
	mat->c1.x = cos(y);
	mat->c1.z = -sin(y);
	mat->c3.x = sin(y);
	mat->c3.z = cos(y);
}

/*
**    c1       c2   c3
** x [ cosz, -sinz, 0]
** y [ sinz,  cosz, 0]
** z [    0,     0, 1]
*/

static void		cam_rotation_z(t_mat3x3 *mat, double z)
{
	mat->c1.x = cos(z);
	mat->c1.y = sin(z);
	mat->c2.x = -sin(z);
	mat->c2.y = cos(z);
}

t_mat3x3		rotate_cam(t_vec3 dir)
{
	t_mat3x3	result;

	result = identity_mat3x3();
	cam_rotation_x(&result, dir.x);
	cam_rotation_y(&result, dir.y);
	cam_rotation_z(&result, dir.z);
	return (result);
}
